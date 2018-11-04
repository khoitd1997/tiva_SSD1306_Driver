#include "ssd1306.h"

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "inc/hw_i2c.h"

#include "inc/hw_ints.h"

#include "inc/hw_memmap.h"

#include "inc/hw_types.h"

#include "driverlib/gpio.h"

#include "driverlib/i2c.h"

#include "driverlib/interrupt.h"

#include "driverlib/pin_map.h"

#include "driverlib/sysctl.h"

#include "driverlib/uart.h"


#include "oled_font.h"
#include "ssd1306_info.h"
#include "ssd1306_utils.h"

void ssd1306Init(void) {
  if (false == SysCtlPeripheralReady(SSD1306_I2C_PERIPH)) {
    SysCtlPeripheralEnable(SSD1306_I2C_PERIPH);
    while (false == SysCtlPeripheralReady(SSD1306_I2C_PERIPH)) {
      // wait for it to be ready
    }
  }

  if (false == SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)) {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while (false == SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)) {
      // wait for it to be ready
    }
  }

  GPIOPinConfigure(GPIO_PB2_I2C0SCL);
  GPIOPinConfigure(GPIO_PB3_I2C0SDA);

  GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
  GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);

  I2CMasterInitExpClk(SSD1306_I2C_BASE, SysCtlClockGet(), false);
}

void ssd1306SwitchDisplay(const bool isOn) {
  ssd1306Write(COMMAND, SSD1306_DISPLAY_ON_OFF | (isOn ? 1 : 0));
}

void ssd1306TurnOn(const bool isFirstTime) {
  if (isFirstTime) {
    const uint32_t totalWaitClock = SSD1306_WARM_UP_TIME_MS * (SysCtlClockGet()) / 1000;
    for (uint32_t waitIndex = 0; waitIndex < totalWaitClock; ++waitIndex) {
      // warm up delay
    }
  }

  ssd1306SwitchDisplay(false);
  ssd1306Write(COMMAND, SSD1306_SETDISPLAYCLOCKDIV);
  ssd1306Write(COMMAND, 0x80);

  ssd1306Write(COMMAND, SSD1306_SETMULTIPLEX);  
  ssd1306Write(COMMAND, SSD1306_LCDHEIGHT - 1);

  ssd1306Write(COMMAND, SSD1306_SETDISPLAYOFFSET);    
  ssd1306Write(COMMAND, 0x0);                         // adjust offset
  ssd1306Write(COMMAND, SSD1306_SETSTARTLINE | 0x0);
  ssd1306Write(COMMAND, SSD1306_CHARGEPUMP);        


  ssd1306Write(COMMAND, 0x14);   // charge pump

  ssd1306Write(COMMAND, SSD1306_SEGREMAP | 0x1);
  ssd1306Write(COMMAND, SSD1306_COMSCANDEC);

  ssd1306Write(COMMAND, SSD1306_SETCOMPINS); 
  ssd1306Write(COMMAND, 0x02);
  ssd1306Write(COMMAND, SSD1306_SETCONTRAST);
  ssd1306Write(COMMAND, 0x8F); // contrast

  ssd1306Write(COMMAND, SSD1306_SETPRECHARGE); 

  ssd1306Write(COMMAND, 0xF1);
  ssd1306Write(COMMAND, SSD1306_SETVCOMDETECT); 
  ssd1306Write(COMMAND, 0x40);
  ssd1306Write(COMMAND, SSD1306_DISPLAYALLON_RESUME);  
  ssd1306Write(COMMAND, SSD1306_NORMALDISPLAY);        

  ssd1306Write(COMMAND, SSD1306_DEACTIVATE_SCROLL);

  ssd1306SwitchDisplay(true); 

  ssd1306Write(COMMAND, SSD1306_MEMORYMODE);
  ssd1306Write(COMMAND, SSD1306_MEMORY_VERTICAL_MODE);

  ssd1306Write(COMMAND, SSD1306_SETLOWCOLUMN);
  ssd1306Write(COMMAND, SSD1306_SETHIGHCOLUMN | 0);
  ssd1306Write(COMMAND, SSD1306_COLUMNADDR);
  ssd1306Write(COMMAND, 0);
  ssd1306Write(COMMAND, SSD1306_LCDWIDTH - 1);

  setPageRange(0, 1);
}

void ssd1306AdjustContrast(const uint8_t contrastVal) {
  ssd1306Write(COMMAND, SSD1306_SETCONTRAST);
  ssd1306Write(COMMAND, contrastVal);
}


void ssd1306ClearDisplay(void) {
  for (uint32_t lineIndex = 0; lineIndex <= SSD1306_MAX_LINE; ++lineIndex) {
    ssd1306SwitchLine(lineIndex);
    ssd1306BeginCom(GDDRAM_DATA);
    for (uint32_t index = 0; index < SSD1306_TOTAL_WRITE - 1; ++index) { ssd1306ContinueCom(0); }
    ssd1306EndCom(0);
  }
}

void ssd1306SwitchLine(const uint32_t lineNum) {
  assert(lineNum <= SSD1306_MAX_LINE);
  setPageRange(lineNum * 2, lineNum * 2 + 1);
  setColumnRange(0, SSD1306_LCDWIDTH - 1);
}

void ssd1306PrintPic(const uint8_t *picBitmap,
                    const uint32_t startColCoordinate,
                    const uint32_t endColCoordinate,
                    const uint32_t startPageCoordinate,
                    const uint32_t endPageCoordinate) {
  ssd1306Write(COMMAND, SSD1306_MEMORYMODE);
  ssd1306Write(COMMAND,
               SSD1306_MEMORY_HORIZONTAL_MODE);  // pic created are in hor mode
  setColumnRange(startColCoordinate, endColCoordinate);
  setPageRange(startPageCoordinate, endPageCoordinate);
  ssd1306WriteList(
      GDDRAM_DATA,
      picBitmap,
      (endColCoordinate - startColCoordinate + 1) * (endPageCoordinate - startPageCoordinate + 1));
}

void ssd1306PrintString(const char *   stringToPrint,
                        const uint32_t lineNum,
                        const uint32_t startCol,
                        const fontSetDesc fontSet) {
  assert(('\0' != stringToPrint[0]));

  // write char bit map vertically
  ssd1306Write(COMMAND, SSD1306_MEMORYMODE);
  ssd1306Write(COMMAND, SSD1306_MEMORY_VERTICAL_MODE);

  ssd1306SwitchLine(lineNum);
  ssd1306BeginCom(GDDRAM_DATA); // write data to GDDRAM mem

  uint32_t glyphIndex  = 0;
  uint32_t stringIndex = 0;
  while (1) {
    glyphIndex = stringToPrint[stringIndex] - fontSet.charOffset;

    for (uint32_t bitIndex = 0; bitIndex < fontSet.descList[glyphIndex].glyphLen; ++bitIndex) {
      ssd1306ContinueCom(fontSet.descList[glyphIndex].glyphBitmap[bitIndex]);
    }
    ++stringIndex;
    if ('\0' == stringToPrint[stringIndex]) {
      ssd1306EndCom(0);
      break;
    }

    // add minimum spacing between char
    for (uint32_t counter = 0; counter < SSD1306_CHAR_SPACING; ++counter) {
      ssd1306ContinueCom(0);
      ssd1306ContinueCom(0);
    }
  }
}