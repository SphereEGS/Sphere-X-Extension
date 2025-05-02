#ifndef PROTOCOL_H
#define PROTOCOL_H

#define LINE_BUFFER_SIZE 10  // number of characters in one command
#define UART_RECEIVE_EMPTY 0

static void protocol_read_line(void);
static void protocol_execute_line(char* line);
void protocol_main_loop(void);

#endif
