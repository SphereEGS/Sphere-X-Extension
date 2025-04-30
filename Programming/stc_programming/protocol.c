#include "project-defs.h"

static char line[LINE_BUFFER_SIZE];
uint8_t char_count = 0;
uint8_t c;

static void protocol_read_line() {

    do { 
      // line end
      if ((c == '\n') || (c == '\r')) {
        line[char_count] = 0; // string termination character, V.IMP for terminal.c to know where the command characters end
        char_count = 0; // reseting to read next command

        // executing line!
        protocol_execute_line(line);

      // throw away whitespaces and control characters
      } else if (c <= ' '){

      // buffer overflow
      } else if (char_count >= (LINE_BUFFER_SIZE-1)) {

        printf("\nBUFFER OVERFLOW!!!!\n");
        char_count = 0;

      // store uart_rx_buffer in line character array
      } else {

        line[char_count++] = c;
      }
    } while (uartGetCharacter(&c, 1) != UART_RECEIVE_EMPTY);
}

static void protocol_execute_line(char* line) {

  if(line[0] == 0) {

    printf("Enter Received..\n\n");
    
  } else {

    LINE_STATUS line_state = terminal_execute_line(line);

    if (line_state == LINE_PASSED) { printf("Command passed..\n\n"); } 
    else if (line_state == LINE_FAILED) { printf("Command Failed..\n\n"); }

  }

}

void protocol_main_loop(void) {
  printf("\nStarting..\n");

  while(1) {
    if (uartGetCharacter(&c, 1) != UART_RECEIVE_EMPTY) {

      protocol_read_line(uart_receive_func_ptr, UART_RECEIVE_EMPTY);

    } 

    // real-time processing
    /* report_toggle_led(); */ //TODO:

  }
}
