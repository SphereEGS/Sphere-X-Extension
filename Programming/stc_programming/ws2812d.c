#include "project-defs.h"

static GpioConfig ws2812_data_line = GPIO_PIN_CONFIG(WS2812_DATA_PORT, WS2812_DATA_PIN, GPIO_BIDIRECTIONAL_MODE);

void ws2812d_init(void) {

  // Initializing
  gpioConfigure(&ws2812_data_line);
  gpioWrite(&ws2812_data_line, 0);


}
