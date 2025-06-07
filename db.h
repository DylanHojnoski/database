#ifndef DB_H
#define DB_H
#include <stdio.h>

typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

#endif
