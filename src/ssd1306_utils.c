#include "ssd1306_utils.h"

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

void ssd1306Write(const Ssd1306ComType comType, const uint8_t dataByte) {
  ssd1306WaitBus();

  I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, false);
  I2CMasterDataPut(SSD1306_I2C_BASE, comType);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_START);
  ssd1306WaitMaster();

  I2CMasterDataPut(SSD1306_I2C_BASE, dataByte);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
  ssd1306WaitMaster();
  ssd1306WaitBus();
}

void ssd1306BeginCom(const Ssd1306ComType comType) {
  ssd1306WaitBus();
  I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, false);
  I2CMasterDataPut(SSD1306_I2C_BASE, comType);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_START);
  ssd1306WaitMaster();
}

void ssd1306EndCom(const uint8_t lastByteToSend) {
  I2CMasterDataPut(SSD1306_I2C_BASE, lastByteToSend);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
  ssd1306WaitMaster();
  ssd1306WaitBus();
}

void ssd1306ContinueCom(const uint8_t dataToSend) {
  I2CMasterDataPut(SSD1306_I2C_BASE, dataToSend);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
  ssd1306WaitMaster();
}

void ssd1306WriteList(const Ssd1306ComType comType, const uint8_t dataByte[],
                      const uint32_t totalByte) {
  assert(totalByte > 1);
  ssd1306WaitBus();

  I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, false);
  I2CMasterDataPut(SSD1306_I2C_BASE, comType);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_START);
  ssd1306WaitMaster();

  uint32_t dataIndex = 0;
  for (dataIndex = 0; dataIndex < totalByte - 1; ++dataIndex) {
    I2CMasterDataPut(SSD1306_I2C_BASE, dataByte[dataIndex]);
    I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
    ssd1306WaitMaster();
  }

  I2CMasterDataPut(SSD1306_I2C_BASE, dataByte[dataIndex]);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
  ssd1306WaitMaster();
  ssd1306WaitBus();
}

void ssd1306WaitMaster(void) {
  while (I2CMasterBusy(SSD1306_I2C_BASE)) {
    // wait until the master is not busy
  }
}

void ssd1306WaitBus(void) {
  while (I2CMasterBusBusy(SSD1306_I2C_BASE)) {
    // wait until the bus is not busy
  }
}

void setColumnRange(const uint32_t startColCoordinate,
                    const uint32_t endColCoordinate) {
  assert(startColCoordinate <= endColCoordinate);
  assert(endColCoordinate < SSD1306_LCDWIDTH);

  ssd1306Write(COMMAND, SSD1306_COLUMNADDR);
  ssd1306Write(COMMAND, startColCoordinate);
  ssd1306Write(COMMAND, endColCoordinate);
}

void setPageRange(const uint32_t startPageCoordinate,
                  const uint32_t endPageCoordinate) {
  assert(startPageCoordinate <= endPageCoordinate);
  assert(endPageCoordinate < SSD1306_LCDPAGE);
  
  ssd1306Write(COMMAND, SSD1306_PAGEADDR);
  ssd1306Write(COMMAND, startPageCoordinate);
  ssd1306Write(COMMAND, endPageCoordinate);
}