#ifndef MY_STRTOK_R_H
#define MY_STRTOK_R_H

#include <stddef.h>

size_t my_strspn(const char *s, const char *accept);
const char *my_strchr(const char *s, char n);
size_t my_strcspn(const char *s1, const char *s2);
char *my_strtok_r(char *str, const char *delim, char **saveptr);

#endif
