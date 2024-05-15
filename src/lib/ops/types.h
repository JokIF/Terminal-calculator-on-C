#ifndef TYPES_OPS__H
#define TYPES_OPS__H
#include <stdint.h>

typedef struct Operation
{
    char ops;
    double (*action)(double, double);
} Operation;

#endif
