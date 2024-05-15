#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <lib/stack/types.h>


char* conv_double_ext2str(char **str, const DoubleExt double_num)
{
    int int_num = (int)double_num.value;
    bool negative = true ? int_num < 0: false;

    char int_str[DOUBLE_EXT_LEN / 2];
    char after_dot_str[DOUBLE_EXT_LEN / 2];

    char tmp_str[DOUBLE_EXT_LEN / 2];
    int i;
    int j;

    for (i = 0; int_num != 0; i++)
    {
        tmp_str[i] = (char)abs(int_num % 10) + '0';
        int_num = (int)(int_num / 10);
    }
    if (negative)
    {
        tmp_str[i++] = '-';
    }
    int len_int_str = i;
    tmp_str[len_int_str] = '\0';
    
    for (i = len_int_str - 1, j = 0; i >= 0; i--, j++)
    {
        int_str[j] = tmp_str[i];
    }
    int_str[len_int_str] = '\0';

    int len_after_dot = double_num.under_dot;
    int after_dot = abs((int)(double_num.value * pow(10, len_after_dot)) % (int)pow(10, len_after_dot));
    for (i = len_after_dot - 1; i >= 0 && after_dot != 0; i--)
    {
        after_dot_str[i] = (char)(after_dot % 10) + '0';
        after_dot = (int)(after_dot / 10);
    }
    after_dot_str[len_after_dot] = '\0';

    *str = strncpy(*str, int_str, len_int_str);
    (*str)[len_int_str] = '.';
    (*str)[len_int_str + 1] = '\0';
    *str = strncat(*str, after_dot_str, len_after_dot);

    return *str;
}



DoubleExt conv_str2double_ext(char *str_num)
{
    DoubleExt num;
    num.value = 0;

    num.under_dot = 0;
    bool degree_flag = false;
    bool negative = false;

    if (*str_num == '-')
    {
        negative = true;
        str_num++;
    }

    char symb;
    while ((symb = *str_num++) != '\0')
    {
        if (degree_flag == true)
        {
            num.under_dot += 1;
        }
        if (symb == '.')
        {
            degree_flag = true;
            continue;
        }            
        num.value *= 10;
        num.value += symb - '0';
    }

    num.value /= pow(10, num.under_dot);
    if (negative == true)
    {
        num.value *= -1;
    }
    return num;
}