#ifndef TOKEN_PARSER__H
#define TOKEN_PARSER__H
#include <lib/parseExp/types.h>

extern Token *create_token();
extern Token *get_token(Token *token, char **exp);

#endif 