#include <lib/excep/excep.h>
#include <lib/stack/stack.h>
#include <lib/loop/types.h>


int end_loop(CaluStack* stack, EndLoopFlag flag_end)
{
    Operation *cur_op;
    DoubleExt *first_num;
    DoubleExt *second_num;

    while ((cur_op = popOp(stack)) != NULL)
    {
        if (cur_op->ops == '(' && flag_end == 0)
            return 0;
        CHECK_NUMS_AMOUNT(first_num = popNum(stack))
        CHECK_NUMS_AMOUNT(second_num = popNum(stack))
        stack->nums->push(stack->nums,
            (DoubleExt){
                .value=cur_op->action(second_num->value, first_num->value),
                .under_dot=-1
            }
        );
    }
    if (stack->nums->len != 1)
    {
        set_text_exception("Incorrect expression: Too many nums into your expression");
        return -1;
    }
    return 0;
}