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
    screen s = createScreenAt(0, term.screencols / 3, 0, term.screenrows / 2, BLU, 8);
    screen s1 = createScreenAt(term.screencols / 3, (term.screencols / 3) * 2, 0, term.screenrows / 2, GRN, 8);
    screen s2 = createScreenAt((term.screencols / 3) * 2, term.screencols, 0, term.screenrows / 2, RED, 8);
    screen s3 = createScreenAt(0, term.screencols, term.screenrows / 2, term.screenrows, MAG, 8);
    for (int x = 0; x < term.screenrows; x++)
    {
        for (int y = 0; y < term.screencols; y++)
        {
            if (renderScreenAt(&s, &b, &term, x, y) == 0 && renderScreenAt(&s1, &b, &term, x, y) == 0 && renderScreenAt(&s2, &b, &term, x, y) == 0 && renderScreenAt(&s3, &b, &term, x, y) == 0)
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