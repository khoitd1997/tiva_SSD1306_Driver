#ifndef _SSD_1306_H
#define _SSD_1306_H
#include <stdbool.h>
#include <stdint.h>

void ssd1306Init(void);
void ssd1306TurnOn(const bool isFirstTime);

void ssd1306AdjustContrast(const uint8_t contrastVal);
void ssd1306ClearDisplay(void);

void ssd1306PrintPic(const uint8_t *picBitmap, const uint32_t startColCoordinate,
                    const uint32_t endColCoordinate,
                    const uint32_t startPageCoordinate,
                    const uint32_t endPageCoordinate);
void ssd1306PrintString(const char *stringToPrint, const uint32_t lineNum, const uint32_t startCol);

void ssd1306SwitchDisplay(const bool isOn);
void ssd1306SwitchLine(const uint32_t lineNum);

#endif