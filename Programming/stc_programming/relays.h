#ifndef RELAYS_H
#define RELAYS_H

#define RELAY_NUM 4
#define DEFAULT_RELAY_TOGGLE_TIME 1000

typedef enum {
  RELAY_ON = 1,
  RELAY_OFF = 0
} relay_state_t;

void relays_init(void);
void relay_set_state(uint8_t ind, relay_state_t relay_state);
uint8_t relay_get_state(uint8_t ind);
void relay_toggle(uint8_t ind);
void relay_toggle_off(uint8_t ind);
void relay_process_realtime(void);
void relay_set_toggle_time(uint32_t period);

#endif
