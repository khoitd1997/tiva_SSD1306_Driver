/**
 * @file ssd1306.h
 * @author Khoi Trinh
 * @brief Header file for ssd1306 main driver
 * @version 0.1
 * @date 2018-11-03
 *
 *
 */

#ifndef _SSD_1306_H
#define _SSD_1306_H
#include <stdbool.h>
#include <stdint.h>

#include "oled_font.h"

/**
 * @brief Configure the hardware like I2C module to be ready for talking with SSD1306
 *
 */
void ssd1306Init(void);
/**
 * @brief Initialize the ssd1306
 *
 * Do things like configure charge pump,
 *
 */
void ssd1306TurnOn(const bool isFirstTime);

/**
 * @brief Adjust contrast of the OLED screen
 *
 * @param contrastVal The contrast value to be set
 */
void ssd1306AdjustContrast(const uint8_t contrastVal);
/**
 * @brief Clear the display and makes it all black
 *
 * Works by blanking the GDDRAM data with 0
 */
void ssd1306ClearDisplay(void);

/**
 * @brief Print picture on oled screen
 *
 * @param picBitmap Arrays containing the bitmap of the picture
 * @param startColCoordinate Column to start printing
 * @param endColCoordinate Column to stop printing(inclusive)
 * @param startPageCoordinate Page to start printing
 * @param endPageCoordinate Page to stop printing(inclusive)
 */
void ssd1306PrintPic(const uint8_t *picBitmap,
                     const uint32_t startColCoordinate,
                     const uint32_t endColCoordinate,
                     const uint32_t startPageCoordinate,
                     const uint32_t endPageCoordinate);
/**
 * @brief Print string onto oled screen
 *
 * @param stringToPrint Character array containing string to print
 * @param lineNum The line at which to print(start at 0), limited by SSD1306_MAX_LINE
 * @param startCol Column at which to start printing
 * @param fontSet The struct containing the font set descriptor for fonts to be used
 */
void ssd1306PrintString(const char *      stringToPrint,
                        const uint32_t    lineNum,
                        const uint32_t    startCol,
                        const fontSetDesc fontSet);

/**
 * @brief Turn display on or off
 *
 * @param isOn Display on if true
 */
void ssd1306SwitchDisplay(const bool isOn);
/**
 * @brief Change the target line to print
 *
 * @param lineNum The line to change to, limited by SSD1306_MAX_LINE
 */
void ssd1306SwitchLine(const uint32_t lineNum);

#endif