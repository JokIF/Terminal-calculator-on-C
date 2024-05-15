#include <stdlib.h>
#include <stdbool.h>
#include <lib/ops/types.h>
#define OPS_LEN 8

double plus_op(double x, double y)
{
    return x + y;
}

double minus_op(double x, double y)
{
    return x - y;
}

double mult_op(double x, double y)
{
    return x * y;
}

double div_op(double x, double y)
{
    return x / y;
}

double hollow_op(double __attribute__((unused)) x, double __attribute__((unused)) y) 
{
    return 0;
}

double (*(*get_ops_acts())[])()
{
    static double ((*ops_acts[])(double, double)) = {&hollow_op, &hollow_op, &mult_op, &plus_op, &hollow_op, &minus_op, &hollow_op, &div_op};
    return &ops_acts;
}

Operation** get_ops()
{
    static Operation *ops[OPS_LEN];
    if (ops[0] != NULL)
    {
        return (Operation **)ops;
    }
    Operation *op;
    for (int i = 0; i < OPS_LEN; i++)
    {
        op = malloc(sizeof(Operation));
        op->ops = '(' + i;
        op->action = (*get_ops_acts())[i];
        ops[i] = op;
    }
    return (Operation **)ops;
}

Operation* get_op(char char_op)
{
    return get_ops()[char_op - '('];
}

uint8_t define_priority(Operation* op)
{
    switch (op->ops)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 3;
    }
    return 0;
}

bool define_op(char symb)
{
    switch (symb)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            return true;
    }
    return false;
}
