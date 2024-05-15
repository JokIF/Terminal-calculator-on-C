#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <lib/stack/stack.h>
#include <lib/parseExp/parser.h>
#include <lib/ops/ops.h>
#include <lib/loop/end_loop.h>
#include <lib/loop/types.h>
#include <lib/excep/excep.h>


int main_loop(CaluStack *stack_c, char *exp)
{
    Token *token = create_token();
    Operation *op_stack;
    Operation *op_exp;
    DoubleExt *tmp_num_first;
    DoubleExt *tmp_num_second;
    LAST(uint8_t)


    while(get_token(token, &exp) != NULL)
    { 
        if (isdigit(*token->symbs))
        {
            LAST_CHECK(LAST_NUM)
            CHECK_STACK_FULL(pushCaluStack(stack_c, NUM_FLAG, token->symbs))
        }
        else if (*token->symbs == ')')
        {
            if (end_loop(stack_c, Efalse) == -1)
                return -1;
        }
        else if (define_op(*token->symbs))
        {
            if (*token->symbs != '(')
            {
                LAST_CHECK(LAST_OP)
            }
                
            
            while(true)
            {
                op_exp = get_op(*token->symbs);
                op_stack = popOp(stack_c);
                if (op_stack == NULL)
                {
                    pushCaluStack(stack_c, OPS_FLAG, &op_exp->ops);
                    break;
                }
                if (define_priority(op_exp) > define_priority(op_stack) || op_stack->ops == '(' || op_exp->ops == '(')
                {
                    pushCaluStack(stack_c, OPS_FLAG, &op_stack->ops);
                    CHECK_STACK_FULL(pushCaluStack(stack_c, OPS_FLAG, &op_exp->ops))
                    break;
                }


                CHECK_NUMS_AMOUNT(tmp_num_first = popNum(stack_c))
                CHECK_NUMS_AMOUNT(tmp_num_second = popNum(stack_c))
                DoubleExt fin_num = {
                    .value = op_stack->action(tmp_num_second->value, tmp_num_first->value),
                    .under_dot = -1
                    };
                CHECK_STACK_FULL(stack_c->nums->push(stack_c->nums, fin_num))
            }
        }
        else
        {
            set_text_exception("Incorrect expression: Incorrect symbols into your expression");
            return -1;
        }
    }
    return end_loop(stack_c, Etrue);
}