#ifndef PROJECT_DEFS_H
#define PROJECT_DEFS_H

/* gpio-hal Settings */
#define RELAY1_PORT
#define RELAY1_PIN
#define RELAY2_PORT
#define RELAY2_PIN
#define RELAY3_PORT
#define RELAY3_PIN
#define RELAY4_PORT
#define RELAY4_PIN
#define LED_RED1_PORT
#define LED_RED1_PIN
#define LED_RED2_PORT
#define LED_RED2_PIN
#define LED_RED3_PORT
#define LED_RED3_PIN
#define LED_RED4_PORT
#define LED_RED4_PIN
#define LED_GREEN1_PORT
#define LED_GREEN1_PIN
#define LED_GREEN2_PORT
#define LED_GREEN2_PIN
#define LED_GREEN3_PORT
#define LED_GREEN3_PIN
#define LED_GREEN4_PORT
#define LED_GREEN4_PIN
#define LED_BLINKING_PORT
#define LED_BLINKING_PIN
#define BUZZER_PORT
#define BUZZER_PIN

/* uart-hal Settings */
#define CONSOLE_SPEED 115200
#define CONSOLE_UART UART1
#define CONSOLE_PIN_CONFIG 0  // TX->P3.1, RX->P3.0

/* timer-hal configs */
#define GLOBAL_TIMER TIMER0
#define GLOBAL_TIMER_ISR timer0_isr
#define GLOBAL_TIMER_INTERRUPT TIMER0_INTERRUPT

// Others 
#define LED_BLINK_PERIOD 400

#include <STC/8G1Kxx/TSSOP20.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <delay.h>
#include <gpio-hal.h>
#include <uart-hal.h>
#include <serial-console.h>
#include <timer-hal.h>
#include "global_timer.h"
#include "leds.h"
#include "buzzer.h"
#include "relays.h"
#include "terminal.h"
#include "protocol.h"


#endif
