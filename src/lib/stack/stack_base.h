#ifndef STACK_BASE__H
#define STACK_BASE__H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE_STACK 20

#define __STACK_S(TYPE) \
    typedef struct stack_##TYPE{ \
        TYPE arr[MAX_SIZE_STACK]; \
        uint32_t len; \
        TYPE* (*pop) (struct stack_##TYPE *stack); \
        bool (*push) (struct stack_##TYPE *stack, TYPE value); \
        TYPE* (*last) (struct stack_##TYPE *stack); \
        } _stack_##TYPE;

#define __STACK_POP_D(TYPE) TYPE *_pop_##TYPE(_stack_##TYPE *stack)
#define __STACK_POP(TYPE) __STACK_POP_D(TYPE) \
{ \
    if (stack->len <= 0) \
        return NULL; \
    return &(stack->arr[--stack->len]); \
}

#define __STACK_PUSH_D(TYPE) bool _push_##TYPE(_stack_##TYPE *stack, TYPE value)
#define __STACK_PUSH(TYPE) \
    __STACK_PUSH_D(TYPE) \
    { \
        if (stack->len < MAX_SIZE_STACK) \
        { \
            stack->arr[stack->len++] = value; \
            return true; \
         } \
         return false; \
    }

#define __STACK_GET_LAST_D(TYPE) TYPE* _get_last_##TYPE(_stack_##TYPE *stack)
#define __STACK_GET_LAST(TYPE) __STACK_GET_LAST_D(TYPE) \
{ \
    if (stack->len <= 0) \
        return NULL; \
    return &(stack->arr[stack->len - 1]); \
}

#define __STACK_CREATE_D(TYPE) _stack_##TYPE *_create_stack_##TYPE()
#define __STACK_CREATE(TYPE) \
    __STACK_CREATE_D(TYPE) \
    { \
        _stack_##TYPE *stack = (_stack_##TYPE *)malloc(sizeof(_stack_##TYPE)); \
        stack->len = 0; \
        stack->pop = _pop_##TYPE; \
        stack->push = _push_##TYPE; \
        stack->last = _get_last_##TYPE; \
        return stack; \
    }



#define STACK_M(TYPE) \
    __STACK_POP(TYPE) \
    __STACK_PUSH(TYPE) \
    __STACK_GET_LAST(TYPE) \
    __STACK_CREATE(TYPE)

#define STACK_D(TYPE) \
    __STACK_S(TYPE) \
    extern __STACK_POP_D(TYPE); \
    extern __STACK_POP_D(TYPE); \
    extern __STACK_GET_LAST_D(TYPE); \
    extern __STACK_CREATE_D(TYPE); 

#endif