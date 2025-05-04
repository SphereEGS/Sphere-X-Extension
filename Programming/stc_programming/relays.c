#include "project-defs.h"

/* static const uint8_t RELAY_STATE_MAP[] = {1, 0}; */

static GpioConfig relay1 = GPIO_PIN_CONFIG(RELAY1_PORT, RELAY1_PIN, GPIO_PUSH_PULL_MODE);
static GpioConfig relay2 = GPIO_PIN_CONFIG(RELAY2_PORT, RELAY2_PIN, GPIO_PUSH_PULL_MODE);
static GpioConfig relay3 = GPIO_PIN_CONFIG(RELAY3_PORT, RELAY3_PIN, GPIO_PUSH_PULL_MODE);
static GpioConfig relay4 = GPIO_PIN_CONFIG(RELAY4_PORT, RELAY4_PIN, GPIO_PUSH_PULL_MODE);

static GpioConfig* relays[RELAY_NUM] = {&relay1, &relay2, &relay3, &relay4};
static volatile relay_state_t relay_toggled_states[RELAY_NUM] = {RELAY_OFF, RELAY_OFF, RELAY_OFF, RELAY_OFF};
static volatile uint32_t relay_toggle_times[RELAY_NUM] = {0, 0, 0, 0};

static uint32_t toggle_time = DEFAULT_RELAY_TOGGLE_TIME;

void relays_init(void) {

  // Initializing the relay pins
  gpioConfigure(&relay1);
  gpioConfigure(&relay2);
  gpioConfigure(&relay3);
  gpioConfigure(&relay4);

  // Setting ALL Pins to LOW,
  gpioWrite(&relay1, 0);
  gpioWrite(&relay2, 0);
  gpioWrite(&relay3, 0);
  gpioWrite(&relay4, 0);

}

void relay_set_state(uint8_t ind, relay_state_t relay_state) {
  //TODO: check if already in toggle state first
  /* gpioWrite(relays[ind], RELAY_STATE_MAP[relay_state]); */
  gpioWrite(relays[ind], relay_state);
}

uint8_t relay_get_state(uint8_t ind) {
  /* return RELAY_STATE_MAP[gpioRead(relays[ind])]; */
  return gpioRead(relays[ind]);
}

void relay_toggle(uint8_t ind) {
  relay_set_state(ind, RELAY_ON);
  relay_toggled_states[ind] = RELAY_ON;
  relay_toggle_times[ind] = get_current_time() + toggle_time; 

}

void relay_toggle_off(uint8_t ind) {
  relay_set_state(ind, RELAY_OFF);
  relay_toggled_states[ind] = RELAY_OFF;
}

void relay_process_realtime(void) {
  for (int ind=0 ; ind<RELAY_NUM ; ind++) {
    if(relay_toggled_states[ind] == RELAY_ON) {
      if(get_current_time() >= relay_toggle_times[ind]) {
        relay_toggle_off(ind);
      }
    }
  }
}

void relay_set_toggle_time(uint32_t period) { toggle_time = period; }
