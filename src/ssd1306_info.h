#ifndef _SSD1306_INFO_H
#define _SSD1306_INFO_H

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

#define SSD1306_I2C_PERIPH SYSCTL_PERIPH_I2C0

#define SSD1306_I2C_BASE I2C0_BASE
#define SSD1306_ADDR 0x3C

//
#define SSD1306_CONTRAST_CMD 0x81
#define SSD1306_DISPLAY_ON_OFF 0xAE
#define SSD1306_ENTIRE_DISPLAY_CMD 0xA4

#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR 0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

#define SSD1306_LCDWIDTH 128
#define SSD1306_LCDHEIGHT 32

#define SSD1306_CONTINUATION_BIT 0x80

// Co bit 0 means only data byte
// D/C# bit 0 means command otw, go to GDDRAM

#endif