#ifndef WS2812D_H
#define WS2812D_H

typedef enum {
  RED = 0xFF0000,
  GREEN = 0x00FF00,
  BLUE = 0x0000FF,
  YELLOW = 0xFFFF00
} color_t;

void ws2812d_init(void);

#endif
