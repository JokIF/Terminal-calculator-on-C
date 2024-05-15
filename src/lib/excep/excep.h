#ifndef EXCEP__H
#define EXCEP__H
#include <stdlib.h>
#include <stdbool.h>
#include <lib/excep/types.h>

extern void set_text_exception(char *text);
extern void print_Exception();


#define IS_NULL(EXP, TEXT) if ((EXP) == NULL) { set_text_exception(#TEXT); return -1; }
#define IS_FALSE(EXP, TEXT) if ((EXP) == false) { set_text_exception(#TEXT); return -1; }
#define CHECK_STACK_FULL(EXP) IS_FALSE(EXP, Stack Error: Stack overloaded)
#define CHECK_NUMS_AMOUNT(EXP) IS_NULL(EXP, Incorrect expression: Not enough numbers in stack)
// ----------------

#define LAST(TYPE) TYPE last_act = 0;
#define LAST_CHECK(LAST_S) \
    if (last_act == LAST_S) \
        { set_text_exception("Incorrect expression: Incorrect order of tokens"); return -1; } \
    else { last_act = LAST_S; }

#define LAST_NUM 1
#define LAST_OP 2

#endif