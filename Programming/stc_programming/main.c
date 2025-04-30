#include "project-defs.h"

/**** MUST DECLARE INTERRUPTS IN MAIN.C FILE AS PER SDCC REQUIREMENT ****/
INTERRUPT(GLOBAL_TIMER_ISR, GLOBAL_TIMER_INTERRUPT);

void main(void) {
  INIT_EXTENDED_SFR();

  // Inits
  EA = 1;
  serialConsoleInitialise(
      CONSOLE_UART, 
      CONSOLE_SPEED, 
      CONSOLE_PIN_CONFIG
      );
  global_timer_init();
  leds_init();
  buzzer_init();
  relays_init();

  // Main Routine
  protocol_main_loop();

}
