#ifndef TERMINAL_H
#define TERMINAL_H

#define MAX_INT_DIGITS 8 
#define INT_ARGS_DEFAULT 0x0FFF

typedef enum {
  COMMAND_NON_MODAL,
  COMMAND_MODAL
} command_modal_status_t;

typedef enum {
  COMMAND_NOT_SET = 0,
  COMMAND_TEST_INT_READING,
  COMMAND_GET_CURRENT_TIME,
  COMMAND_RELAY_SET,
  COMMAND_RELAY_TOGGLE,
  COMMAND_LED,
} command_type_t;

typedef struct {
  command_type_t command_type;
  int16_t i;
  int16_t j;
  command_modal_status_t command_modal_status;
} command_t;

typedef enum {
  LINE_PASSED, 
  LINE_FAILED
} LINE_STATUS;

bool read_int(char *line, uint8_t *char_count, int16_t *value_ptr);
void command_reset(command_t* command);
LINE_STATUS terminal_execute_line(char* line);

#endif
