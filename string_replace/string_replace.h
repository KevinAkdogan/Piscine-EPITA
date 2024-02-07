#ifndef STRING_REPLACE_H
#define STRING_REPLACE_H

#include <stddef.h>

size_t my_strlen(const char *s);
int rep(char c, const char *s, size_t size);
char *string_replace(char c, const char *str, const char *pattern);

#endif
