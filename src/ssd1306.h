#ifndef _SSD_1306_H
#define _SSD_1306_H
#include <stdbool.h>
#include <stdint.h>

void ssd1306Init(void);
void ssd1306AdjustContrast(const uint8_t contrastVal);
void ssd1306Switch(const bool isOn);
void ssd1306TurnOn(void);
void ssd1306SwitchEntireDisplay(const bool ignoreRAM);
#endif