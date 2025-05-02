#include "project-defs.h"

static const uint8_t RELAY_STATE_MAP[] = {1, 0};

static GpioConfig relay1 = GPIO_PIN_CONFIG(RELAY1_PORT, RELAY1_PIN, GPIO_PUSH_PULL_MODE);
static GpioConfig relay2 = GPIO_PIN_CONFIG(RELAY2_PORT, RELAY2_PIN, GPIO_PUSH_PULL_MODE);
static GpioConfig relay3 = GPIO_PIN_CONFIG(RELAY3_PORT, RELAY3_PIN, GPIO_PUSH_PULL_MODE);
static GpioConfig relay4 = GPIO_PIN_CONFIG(RELAY4_PORT, RELAY4_PIN, GPIO_PUSH_PULL_MODE);

static GpioConfig* relays[RELAY_NUM] = {&relay1, &relay2, &relay3, &relay4};

void relays_init(void) {

  // Initializing the relay pins
  gpioConfigure(&relay1);
  gpioConfigure(&relay2);
  gpioConfigure(&relay3);
  gpioConfigure(&relay4);

  // Setting ALL Pins to HIGH, Optocoupler means it's active low
  gpioWrite(&relay1, 1);
  gpioWrite(&relay2, 1);
  gpioWrite(&relay3, 1);
  gpioWrite(&relay4, 1);

}

void relay_set_state(uint8_t ind, relay_state_t relay_state) {
  gpioWrite(relays[ind], RELAY_STATE_MAP[relay_state]);
}

uint8_t relay_get_state(uint8_t ind) {
  return RELAY_STATE_MAP[gpioRead(relays[ind])];
}

