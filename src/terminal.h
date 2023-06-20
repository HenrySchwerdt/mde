#ifndef terminal_h
#define terminal_h
#include "mde.h"

typedef struct
{
    int screenrows;
    int screencols;
    struct termios orig_termios;
} terminal;

void disableRawMode(terminal *term);
void enableRawMode(terminal *term);
int getCursorPosition(int *rows, int *cols);
int getWindowSize(int *rows, int *cols);
terminal initTerminal();

#endif