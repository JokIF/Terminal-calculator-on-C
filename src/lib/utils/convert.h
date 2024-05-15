#ifndef UTILS_CONVERT__H
#define UTILS_CONVERT__H
#include <lib/stack/types.h>

extern char* conv_double_ext2str(char **str, const DoubleExt double_num);
extern DoubleExt conv_str2double_ext(char *str_num);

#endif
