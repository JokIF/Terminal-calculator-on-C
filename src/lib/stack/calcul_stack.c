#include <stdio.h>
#include <stdlib.h>
#include <lib/stack/types.h>
#include <lib/utils/convert.h>
#include <lib/ops/ops.h>

CaluStack* createCaluStack()
{
    CaluStack* calu_stack = (CaluStack*)malloc(sizeof(CaluStack));
    calu_stack->nums = _create_stack_DoubleExt();
    calu_stack->ops = _create_stack_Operation();
    return calu_stack;
}

bool pushCaluStack(CaluStack* calstack, stack_flag flag, char* symb)
{
    switch (flag)
    {
    case NUM_FLAG:

        if (calstack->nums->push(calstack->nums, conv_str2double_ext(symb)) == false)
        {
            return false;
        };
        break;
    case OPS_FLAG:
        if (calstack->ops->push(calstack->ops, *get_op(symb[0])) == false)
        {
            return false;
        }
        break;
    }
    return true;
}

DoubleExt* popNum(CaluStack* calstack)
{
    return calstack->nums->pop(calstack->nums);
}

Operation* popOp(CaluStack* calstack)
{
    return calstack->ops->pop(calstack->ops);
}

Operation* lastOp(CaluStack* CaluStack)
{
    return CaluStack->ops->last(CaluStack->ops);
}