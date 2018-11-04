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

uint8_t ssd1306ReadReg(const uint8_t regAddr) {
  ssd1306WaitBus();

  I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, false);
  I2CMasterDataPut(SSD1306_I2C_BASE, regAddr);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_START);
  ssd1306WaitMaster();

  I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, true);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
  ssd1306WaitMaster();
  ssd1306WaitBus();

  return I2CMasterDataGet(SSD1306_I2C_BASE);
}

void ssd1306ReadRegList(const uint8_t startRegAddr, uint8_t *recvData,
                        const uint8_t totalData) {
  assert(NULL != recvData);
  assert(totalData > 1);

  ssd1306WaitBus();

  I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, false);
  I2CMasterDataPut(SSD1306_I2C_BASE, startRegAddr);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_SEND_START);
  ssd1306WaitMaster();

  I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, true);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
  ssd1306WaitMaster();
  recvData[0] = I2CMasterDataGet(SSD1306_I2C_BASE);

  uint8_t dataIndex = 1;
  for (dataIndex = 1; dataIndex < totalData - 1; ++dataIndex) {
    I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, true);
    I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_RECEIVE_CONT);
    ssd1306WaitMaster();
    recvData[dataIndex] = I2CMasterDataGet(SSD1306_I2C_BASE);
  }

  I2CMasterSlaveAddrSet(SSD1306_I2C_BASE, SSD1306_ADDR, true);
  I2CMasterControl(SSD1306_I2C_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
  ssd1306WaitMaster();
  ssd1306WaitBus();
  recvData[dataIndex] = I2CMasterDataGet(SSD1306_I2C_BASE);
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