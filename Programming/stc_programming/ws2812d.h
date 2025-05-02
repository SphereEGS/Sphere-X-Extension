#ifndef WS2812D_H
#define WS2812D_H

#define LED_NUM 4

#define SUPPORTED_COLORS_NUM 8
// Color definitions in GRB format (not RGB)
typedef enum {
    COLOR_BLACK   = 0x000000,  // All off
    COLOR_RED     = 0x00FF00,  // G=0, R=255, B=0
    COLOR_GREEN   = 0xFF0000,  // G=255, R=0, B=0
    COLOR_BLUE    = 0x0000FF,  // G=0, R=0, B=255
    COLOR_YELLOW  = 0xFFFF00,  // G=255, R=255, B=0
    COLOR_CYAN    = 0xFF00FF,  // G=255, R=0, B=255
    COLOR_MAGENTA = 0x00FFFF,  // G=0, R=255, B=255
    COLOR_WHITE   = 0xFFFFFF   // G=255, R=255, B=255
} color_t;

void ws2812d_init(void);
static void send_bit_0(void);
static void send_bit_1(void);
static void send_byte(uint8_t byte);
static void reset(void);
void ws2812d_set_led_color(uint8_t ind, color_t color);
color_t ind_to_color_map(uint8_t ind);


#endif
