#include "project-defs.h"

static GpioConfig buzzer = GPIO_PIN_CONFIG(BUZZER_PORT, BUZZER_PIN, GPIO_BIDIRECTIONAL_MODE);

void buzzer_init(void) {

  // Initializing the buzzer pins
  gpioConfigure(&buzzer);

  // Setting initial condition to OFF
  gpioWrite(&buzzer, 0);


}
