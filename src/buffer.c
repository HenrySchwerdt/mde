#include "buffer.h"

void append(buffer *buf, char *s, int len)
{

    char *new = realloc(buf->s, buf->len + len);
    if (new == NULL)
        return;
    memcpy(&new[buf->len], s, len);
    buf->s = new;
    buf->len += len;
}

buffer initBuffer()
{
    buffer bf;
    bf.s = NULL;
    bf.len = 0;
    return bf;
}