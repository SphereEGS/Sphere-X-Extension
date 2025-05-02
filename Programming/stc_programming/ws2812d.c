#include "project-defs.h"

// Pin Assignment
static GpioConfig ws2812_data_line = GPIO_PIN_CONFIG(WS2812_DATA_PORT, WS2812_DATA_PIN, GPIO_PUSH_PULL_MODE);

// Buffer to hold the value of each LED, to enable single LED change and remembering the vlaue of the rest
static color_t led_color_buffer[LED_NUM] = {0};

/* extern const color_t IND_TO_COLOR_MAP[SUPPORTED_COLORS_NUM] = {COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_YELLOW, COLOR_CYAN, COLOR_MAGENTA, COLOR_WHITE}; */
/* extern color_t IND_TO_COLOR_MAP[SUPPORTED_COLORS_NUM]; */
const color_t IND_TO_COLOR_MAP[SUPPORTED_COLORS_NUM] = {COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_YELLOW, COLOR_CYAN, COLOR_MAGENTA, COLOR_WHITE};

color_t ind_to_color_map(uint8_t ind) { return IND_TO_COLOR_MAP[ind]; }


void ws2812d_init(void) {

  // Initializing
  gpioConfigure(&ws2812_data_line);

  // Setting ALL Pins to HIGH, Optocoupler means it's active low
  gpioWrite(&ws2812_data_line, 1);

  /* IND_TO_COLOR_MAP[0] = {COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_YELLOW, COLOR_CYAN, COLOR_MAGENTA, COLOR_WHITE}; */

  /* IND_TO_COLOR_MAP[0] = COLOR_BLACK; */
  /* IND_TO_COLOR_MAP[1] = COLOR_RED; */
  /* IND_TO_COLOR_MAP[2] = COLOR_GREEN; */
  /* IND_TO_COLOR_MAP[3] = COLOR_BLUE; */
  /* IND_TO_COLOR_MAP[4] = COLOR_YELLOW; */
  /* IND_TO_COLOR_MAP[5] = COLOR_CYAN; */
  /* IND_TO_COLOR_MAP[6] = COLOR_MAGENTA; */
  /* IND_TO_COLOR_MAP[7] = COLOR_BLACK; */

}

static void send_bit_0(void) {
  gpioWrite(&ws2812_data_line, 0);
  gpioWrite(&ws2812_data_line, 1);
  delay1us(1);

}

static void send_bit_1(void) {
  gpioWrite(&ws2812_data_line, 0);
  delay1us(1);
  gpioWrite(&ws2812_data_line, 1);

}

// Array of function pointers for bit transmission
static void (*const send_bit[2])(void) = {
    send_bit_0,  // Index 0
    send_bit_1   // Index 1
};

static void send_color(color_t color) {
  for (int i = 23 ; i >=0 ; i--) {
    send_bit[(color >> i) & 1]();
  }
}

static void reset(void) {
  gpioWrite(&ws2812_data_line, 1);
  delay10us(30);
}

void ws2812d_set_led_color(uint8_t ind, color_t color) {
  // Setting new color
  led_color_buffer[ind] = color;

  // Reset Signal
  reset();

  // Send new color order
  EA = 0;
  for (int i = 0; i < LED_NUM ; i++) {
    send_color(led_color_buffer[i]);
  }
  EA = 1;

  reset();

}

