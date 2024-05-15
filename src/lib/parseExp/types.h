#ifndef TYPES_PARSE_EXP__H
#define TYPES_PARSE_EXP__H
#define TOKEN_LEN 10
#include <stdlib.h>


typedef struct Token
{
    char *symbs;
    size_t len;
} Token;


#endif