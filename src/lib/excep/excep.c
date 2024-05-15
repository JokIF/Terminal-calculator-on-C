#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <lib/excep/types.h>

static bool set_text = false;

Exception get_Exception()
{
    static Exception excep;
    static char text[40];
    excep.text = text;
    return excep;
}

void set_text_exception(char *text)
{
    set_text = true;
    Exception excep = get_Exception();
    strcpy(excep.text, text);
}

void print_Exception()
{
    if (set_text == false)
    {
        printf("somthing wrong\n");
        return;
    }
    Exception excep = get_Exception();
    printf("%s\n", excep.text);
}