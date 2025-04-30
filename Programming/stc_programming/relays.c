#include "project-defs.h"

static GpioConfig relay1 = GPIO_PIN_CONFIG(RELAY1_PORT, RELAY1_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig relay2 = GPIO_PIN_CONFIG(RELAY2_PORT, RELAY2_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig relay3 = GPIO_PIN_CONFIG(RELAY3_PORT, RELAY3_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig relay4 = GPIO_PIN_CONFIG(RELAY4_PORT, RELAY4_PIN, GPIO_BIDIRECTIONAL_MODE);

void relays_init(void) {

  // Initializing the relay pins
  gpioConfigure(&relay1);
  gpioConfigure(&relay2);
  gpioConfigure(&relay3);
  gpioConfigure(&relay4);

  // Setting ALL Pins to GND, so as keep relays IDLE
  gpioWrite(&relay1, 0);
  gpioWrite(&relay2, 0);
  gpioWrite(&relay3, 0);
  gpioWrite(&relay4, 0);


}

