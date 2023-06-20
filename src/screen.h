#ifndef screen_h
#define screen_h
#include "mde.h"
#include "buffer.h"
#include "terminal.h"
typedef enum
{
    MAXIMIZED = 0b1,
    STACKING = 0b10,
    FLOATING = 0b100,
    LAYOUT = 0b1000,
} screen_layout;

typedef struct
{
    int startCol;
    char *color;
    int colorLen;
    int endCol;
    int startRow;
    int endRow;
    screen_layout layout;
} screen;

int renderScreenAt(screen *scr, buffer *buf, terminal *term, int row, int col);

screen createScreenAt(int startCol, int endCol, int startRow, int endRow, char *color, int colorLen);

#endif