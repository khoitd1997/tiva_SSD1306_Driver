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

#include "utils/uartstdio.h"

#include "tiva_utils/bit_manipulation.h"

#include "ssd1306.h"

int main(void) {
  for (uint32_t waitIndex = 0; waitIndex < 5000000; ++waitIndex) {
  }
  ssd1306Init();

  // Enable the GPIO Peripheral used by the UART.
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)) {
  }

  // Enable UART0
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0)) {
  }

  // Configure GPIO Pins for UART mode.
  GPIOPinConfigure(GPIO_PA0_U0RX);
  GPIOPinConfigure(GPIO_PA1_U0TX);
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

  // Use the internal 16MHz oscillator as the UART clock source.
  UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

  // Initialize the UART for console I/O.
  UARTStdioConfig(0, 115200, 16000000);

  UARTprintf("Starting sd1306 test\n");

  //   ssd1306SwitchEntireDisplay(true);
  ssd1306TurnOn();
  for (;;) {
    // ssd1306SwitchEntireDisplay(true);
    // ssd1306Switch(true);
    // ssd1306AdjustContrast(50);
    for (uint32_t waitIndex = 0; waitIndex < 50000; ++waitIndex) {
    }
    // ssd1306AdjustContrast(250);
    for (uint32_t waitIndex = 0; waitIndex < 50000; ++waitIndex) {
    }
  }
  return 0;
}
