#ifndef STACK_TYPES__H
#define STACK_TYPES__H

#include <stdint.h>
#include <lib/stack/stack_base.h>
#include <lib/ops/types.h>
#define DOUBLE_EXT_LEN 40


typedef char stack_flag;
#define NUM_FLAG 1
#define OPS_FLAG 2


typedef struct double_ext
{
    double value;
    int under_dot;
} DoubleExt;

STACK_D(Operation)
STACK_D(DoubleExt)

typedef struct CaluStack
{
    _stack_DoubleExt *nums;
    _stack_Operation *ops;
} CaluStack;

#endif