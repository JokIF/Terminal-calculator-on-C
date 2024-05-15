#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <lib/parseExp/types.h>
#include <lib/ops/ops.h>


Token *create_token()
{
    Token *token = (Token *)malloc(sizeof(Token));
    token->symbs = (char *)malloc(TOKEN_LEN);
    token->len = 0;
    return token;
}


Token *get_token(Token *token, char **exp)
{
    char symb;
    size_t len_dig_token = 0;
    bool is_dig = false;
    char *dig_start;

    while ((symb = *(*exp)++) != '\0')
    {
        if (define_op(symb) == true)
        {
            strncpy(token->symbs, &symb, 1);
            token->symbs[1] = '\0';
            return token;
        }
        dig_start = (*exp) - 1;
        while(isdigit(symb) || symb == '.')
        {
            len_dig_token++;
            is_dig = true;
            symb = *(*exp)++;
        }
        if (is_dig == true)
        {
            strncpy(token->symbs, dig_start, len_dig_token);
            token->symbs[len_dig_token] = '\0';
            (*exp)--;
            return token;
        }
    }
    (*exp)--;
    return NULL;
}