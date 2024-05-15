#include <lib/stack/stack.h>
#include <lib/loop/main_loop.h>
#include <lib/excep/excep.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) // 2 + 9.3 / 3 + 16 / ((2+2) * 2 ) * 10 = 25.1
{
    if (argc != 2)
    {
        printf("error");
        return -1;
    }
    CaluStack *stack_c = createCaluStack();
    int status = main_loop(stack_c, argv[1]);
    if (status == 0)
    {
        printf("%lf\n", popNum(stack_c)->value);
        return 0;
    }
    else
    {
        print_Exception();
        return -1;
    }
    
    return -1;
}