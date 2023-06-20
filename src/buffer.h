#ifndef buffer_h
#define buffer_h
#include "mde.h"

typedef struct
{
    char *s;
    int len;
} buffer;

void append(buffer *buf, char *s, int len);
buffer initBuffer();

#endif