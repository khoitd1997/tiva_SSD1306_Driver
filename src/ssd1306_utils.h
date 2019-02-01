/**
 * @file ssd1306_utils.h
 * @author Khoi Trinh
 * @brief Header file containg declaration of utils functions for ssd1306
 * @version 0.1
 * @date 2018-11-03
 *
 *
 */

#ifndef _SSD1306_UTILS_H
#define _SSD1306_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Enum describing the type of communication that can be done with the SSD1306
 *
 */
typedef enum { COMMAND = 0b0000000, GDDRAM_DATA = 0b01000000 } Ssd1306ComType;

/**
 * @brief Single I2C write to the SSD1306
 *
 * @param comType Communication type of this transaction
 * @param dataByte The data byte to be written
 */
void ssd1306Write(const Ssd1306ComType comType, const uint8_t dataByte);
/**
 * @brief List I2C write to the SSD1306
 *
 * @param comType Communication type of this transaction
 * @param dataByte List containing the bytes to be transferred
 * @param totalByte Total bytes to be transferred
 */
void ssd1306WriteList(const Ssd1306ComType comType,
                      const uint8_t        dataByte[],
                      const uint32_t       totalByte);

/**
 * @brief Helper function to wait for master to finnish i2c
 *
 */
void ssd1306WaitMaster(void);
/**
 * @brief Helper function to wait for all transaction on the i2c bus to finnish
 *
 */
void ssd1306WaitBus(void);

/**
 * @brief Helper function uses for making i2c transaction to initiate contact with ssd1306
 *
 * @param comType Communication type of this transaction
 */
void ssd1306BeginCom(const Ssd1306ComType comType);
/**
 * @brief Helper function uses for ending i2c transaction
 *
 * @param lastByteToSend The last byte to be sent
 */
void ssd1306EndCom(const uint8_t lastByteToSend);
/**
 * @brief Transfer the data and let SSD1306 know transaction will still continue
 *
 * @param dataToSend The data byte to be sent
 */
void ssd1306ContinueCom(const uint8_t dataToSend);

/**
 * @brief Set the Column Range that can be printed on OLED
 *
 * @param startColCoordinate Column to start printing
 * @param endColCoordinate Column to stop printing(inclusive)
 */
void setColumnRange(const uint32_t startColCoordinate, const uint32_t endColCoordinate);

/**
 * @brief Set the Page Range that can be printed on OLED
 *
 * @param startPageCoordinate Page to start printing
 * @param endPageCoordinate Page to stop printing(inclusive)
 */
void setPageRange(const uint32_t startPageCoordinate, const uint32_t endPageCoordinate);

#ifdef __cplusplus
}
#endif
#endif