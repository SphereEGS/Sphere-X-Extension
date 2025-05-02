#ifndef PROJECT_DEFS_H
#define PROJECT_DEFS_H

/* gpio-hal Settings */
#define WS2812_DATA_PORT 1
#define WS2812_DATA_PIN 0
#define BUZZER_PORT 1
#define BUZZER_PIN 1
#define RELAY1_PORT 3
#define RELAY1_PIN 7
#define RELAY2_PORT 3
#define RELAY2_PIN 6
#define RELAY3_PORT 3
#define RELAY3_PIN 5
#define RELAY4_PORT 3
#define RELAY4_PIN 4

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
#include <stdint.h>
#include <delay.h>
#include <gpio-hal.h>
#include <uart-hal.h>
#include <serial-console.h>
#include <timer-hal.h>
#include "global_timer.h"
#include "ws2812d.h"
#include "buzzer.h"
#include "relays.h"
#include "terminal.h"
#include "protocol.h"


#endif
