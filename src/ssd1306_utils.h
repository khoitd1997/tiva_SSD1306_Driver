#ifndef _SSD1306_UTILS_H
#define _SSD1306_UTILS_H

#include <stdint.h>

typedef enum { COMMAND = 0b0000000, GDDRAM_DATA = 0b01000000 } Ssd1306ComType;

void ssd1306Write(const Ssd1306ComType comType, const uint8_t dataByte);
void ssd1306WriteList(const Ssd1306ComType comType, const uint8_t dataByte[],
                      const uint32_t totalByte);

uint8_t ssd1306ReadReg(const uint8_t regAddr);
void ssd1306ReadRegList(const uint8_t startRegAddr, uint8_t *recvData,
                        const uint8_t totalData);
void ssd1306WaitMaster(void);
void ssd1306WaitBus(void);

#endif