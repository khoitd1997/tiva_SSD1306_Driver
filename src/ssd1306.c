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

#include "tiva_utils/bit_manipulation.h"

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

  //   ssd1306Reset();
  // do dummy receive
  //   I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, true);
  //   I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
  //   ssd1306WaitMaster();
}

void ssd1306SwitchEntireDisplay(const bool ignoreRAM) {
  ssd1306Write(COMMAND, SSD1306_ENTIRE_DISPLAY_CMD | (ignoreRAM ? 1 : 0));
}

void ssd1306Switch(const bool isOn) {
  ssd1306Write(COMMAND, SSD1306_DISPLAY_ON_OFF | (isOn ? 1 : 0));
}

void ssd1306TurnOn(void) {
  ssd1306Switch(false);
  ssd1306Write(COMMAND, SSD1306_SETDISPLAYCLOCKDIV);
  ssd1306Write(COMMAND, 0x80);

  ssd1306Write(COMMAND, SSD1306_SETMULTIPLEX); // 0xA8
  ssd1306Write(COMMAND, SSD1306_LCDHEIGHT - 1);

  ssd1306Write(COMMAND, SSD1306_SETDISPLAYOFFSET);   // 0xD3
  ssd1306Write(COMMAND, 0x0);                        // no offset
  ssd1306Write(COMMAND, SSD1306_SETSTARTLINE | 0x0); // line #0
  ssd1306Write(COMMAND, SSD1306_CHARGEPUMP);         // 0x8D

  // charge pump
  ssd1306Write(COMMAND, 0x14);

  ssd1306Write(COMMAND, SSD1306_MEMORYMODE); // 0x20
  ssd1306Write(COMMAND, 0x00);               // 0x0 act like ks0108
  ssd1306Write(COMMAND, SSD1306_SEGREMAP | 0x1);
  ssd1306Write(COMMAND, SSD1306_COMSCANDEC);

  ssd1306Write(COMMAND, SSD1306_SETCOMPINS); // 0xDA
  ssd1306Write(COMMAND, 0x02);
  ssd1306Write(COMMAND, SSD1306_SETCONTRAST); // 0x81
  ssd1306Write(COMMAND, 0x8F);

  ssd1306Write(COMMAND, SSD1306_SETPRECHARGE); // 0xd9

  ssd1306Write(COMMAND, 0xF1);
  ssd1306Write(COMMAND, SSD1306_SETVCOMDETECT); // 0xDB
  ssd1306Write(COMMAND, 0x40);
  ssd1306Write(COMMAND, SSD1306_DISPLAYALLON_RESUME); // 0xA4
  ssd1306Write(COMMAND, SSD1306_NORMALDISPLAY);       // 0xA6

  ssd1306Write(COMMAND, SSD1306_DEACTIVATE_SCROLL);

  ssd1306Switch(true); //--turn on oled panel
}

void ssd1306AdjustContrast(const uint8_t contrastVal) {
  uint8_t byteList[2] = {0x81};
  byteList[1] = contrastVal;
  ssd1306WriteList(COMMAND, byteList, 2);
}
