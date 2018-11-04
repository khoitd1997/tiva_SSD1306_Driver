#ifndef _SSD1306_UTILS_H
#define _SSD1306_UTILS_H

#include <stdint.h>

typedef enum { COMMAND = 0b0000000, GDDRAM_DATA = 0b01000000 } Ssd1306ComType;

void ssd1306Write(const Ssd1306ComType comType, const uint8_t dataByte);
void ssd1306WriteList(const Ssd1306ComType comType, const uint8_t dataByte[],
                      const uint32_t totalByte);

void ssd1306WaitMaster(void);
void ssd1306WaitBus(void);

void ssd1306BeginCom(const Ssd1306ComType comType);
void ssd1306EndCom(const uint8_t lastByteToSend);
void ssd1306ContinueCom(const uint8_t dataToSend);

void setColumnRange(const uint32_t startColCoordinate,
                    const uint32_t endColCoordinate);

void setPageRange(const uint32_t startPageCoordinate,
                  const uint32_t endPageCoordinate);

#endif