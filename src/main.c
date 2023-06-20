#include "mde.h"
#include "terminal.h"
#include "buffer.h"
#include "screen.h"
#include "ansi.h"
int main()
{
    terminal term = initTerminal();
    enableRawMode(&term);
    getWindowSize(&term.screenrows, &term.screencols);

    buffer b = initBuffer();
    screen s = createScreenAt(0, term.screencols / 2, 0, term.screenrows, BLU, 8);
    screen s1 = createScreenAt(term.screencols / 2, term.screencols, 0, term.screenrows, GRN, 8);
    for (int x = 0; x < term.screenrows; x++)
    {
        for (int y = 0; y < term.screencols; y++)
        {
            if (renderScreenAt(&s, &b, &term, x, y) == 0 && renderScreenAt(&s1, &b, &term, x, y) == 0)
            {
                append(&b, " ", 2);
            }
        }
        append(&b, "\n\r", 3);
    }
    write(STDOUT_FILENO, b.s, b.len);
    disableRawMode(&term);
    return 0;
}