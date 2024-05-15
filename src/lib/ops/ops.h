#ifndef OPS__H
#define OPS__H
#include <stdint.h>
#include <lib/ops/types.h>

extern Operation* get_op(char char_op);
extern uint8_t define_priority(Operation* op);
extern bool define_op(char symb);

#endif