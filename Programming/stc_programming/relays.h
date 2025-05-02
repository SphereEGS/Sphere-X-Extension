#ifndef RELAYS_H
#define RELAYS_H

#define RELAY_NUM 4

typedef enum {
  RELAY_ON = 0,
  RELAY_OFF = 1
} relay_state_t;

void relays_init(void);
void relay_set_state(uint8_t ind, relay_state_t relay_state);
uint8_t relay_get_state(uint8_t ind);

#endif
