#include "screen.h"
#include "ansi.h"

int renderScreenAt(screen *scr, buffer *buf, terminal *term, int row, int col)
{
    if (row >= scr->startRow && row <= scr->endRow && col >= scr->startCol && col <= scr->endCol)
    {
        int isLeftScreen = scr->startCol == 0 && scr->endCol != term->screencols - 1;
        int isRightScreen = scr->startCol != 0;
        // Append Borders
        if (row == scr->startRow && col == scr->startCol)
        {
            append(buf, scr->color, scr->colorLen);
            append(buf, "┌", 4);
            append(buf, CRESET, 5);
            return 1;
        }
        else if (row == scr->startRow && col == scr->endCol - 1)
        {
            append(buf, scr->color, scr->colorLen);
            if (isLeftScreen)
            {

                append(buf, "┬", 4);
            }
            else
            {
                append(buf, "┐", 4);
            }
            append(buf, CRESET, 5);
            return 1;
        }
        else if (row == scr->endRow - 1 && col == scr->startCol)
        {
            append(buf, scr->color, scr->colorLen);
            append(buf, "└", 4);
            append(buf, CRESET, 5);
            return 1;
        }
        else if (row == scr->endRow - 1 && col == scr->endCol - 1)
        {
            append(buf, scr->color, scr->colorLen);
            if (isLeftScreen)
            {
                append(buf, "┴", 4);
            }
            else
            {
                append(buf, "┘", 4);
            }
            append(buf, CRESET, 5);

            return 1;
        }
        else if ((row == scr->startRow || row == scr->endRow - 1) && (col != scr->startCol && col != scr->endCol - 1))
        {
            append(buf, scr->color, scr->colorLen);
            append(buf, "─", 4);
            append(buf, CRESET, 5);
            return 1;
        }
        else if ((col == scr->startCol) && (row != scr->startRow && row != scr->endRow - 1))
        {
            if (isRightScreen)
            {
                return 0;
            }
            append(buf, scr->color, scr->colorLen);
            append(buf, "│", 4);
            append(buf, CRESET, 5);
            return 1;
        }
        else if ((col == scr->endCol - 1) && (row != scr->startRow && row != scr->endRow - 1))
        {

            append(buf, scr->color, scr->colorLen);
            append(buf, "│", 4);
            append(buf, CRESET, 5);
            return 1;
        }
        // Append lines
        if ((col == scr->startCol + 1) && row != scr->startRow && row != scr->endRow - 1)
        {
            append(buf, scr->color, scr->colorLen);
            append(buf, "~", 2);
            append(buf, CRESET, 5);
            return 1;
        }
    }
    return 0;
}

screen createScreenAt(int startCol, int endCol, int startRow, int endRow, char *color, int colorLen)
{
    screen sc;
    sc.startCol = startCol;
    sc.endCol = endCol;
    sc.startRow = startRow;
    sc.endRow = endRow;
    sc.layout = MAXIMIZED;
    sc.color = color;
    sc.colorLen = colorLen;
    return sc;
}