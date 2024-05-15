#ifndef STACK__H
#define STACK__H
#include <stdbool.h>
#include <lib/stack/types.h>

extern CaluStack* createCaluStack();
extern bool pushCaluStack(CaluStack* calstack, stack_flag flag, char* symb);
extern DoubleExt *popNum(CaluStack* calstack);
extern Operation *popOp(CaluStack* calstack);
extern Operation *lastOp(CaluStack* CaluStack);

#endif