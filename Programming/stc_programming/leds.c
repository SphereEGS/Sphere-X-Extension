#include "project-defs.h"

static GpioConfig led_green1 = GPIO_PIN_CONFIG(LED_GREEN1_PORT, LED_GREEN1_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig led_green2 = GPIO_PIN_CONFIG(LED_GREEN2_PORT, LED_GREEN2_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig led_green3 = GPIO_PIN_CONFIG(LED_GREEN3_PORT, LED_GREEN3_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig led_green4 = GPIO_PIN_CONFIG(LED_GREEN4_PORT, LED_GREEN4_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig led_red1 = GPIO_PIN_CONFIG(LED_RED1_PORT, LED_RED1_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig led_red2 = GPIO_PIN_CONFIG(LED_RED2_PORT, LED_RED2_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig led_red3 = GPIO_PIN_CONFIG(LED_RED3_PORT, LED_RED3_PIN, GPIO_BIDIRECTIONAL_MODE);
static GpioConfig led_red4 = GPIO_PIN_CONFIG(LED_RED4_PORT, LED_RED4_PIN, GPIO_BIDIRECTIONAL_MODE);


void leds_init(void) {

  // Initializing the led pins
  gpioConfigure(&led_green1);
  gpioConfigure(&led_green2);
  gpioConfigure(&led_green3);
  gpioConfigure(&led_green4);
  gpioConfigure(&led_red1);
  gpioConfigure(&led_red2);
  gpioConfigure(&led_red3);
  gpioConfigure(&led_red4);

  // Setting ALL Pins to GND, so as keep leds OFF
  gpioWrite(&led_green1, 0);
  gpioWrite(&led_green2, 0);
  gpioWrite(&led_green3, 0);
  gpioWrite(&led_green4, 0);
  gpioWrite(&led_red1, 0);
  gpioWrite(&led_red2, 0);
  gpioWrite(&led_red3, 0);
  gpioWrite(&led_red4, 0);

}
