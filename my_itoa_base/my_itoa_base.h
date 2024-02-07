#ifndef MY_ITOA_BASE_H
#define MY_ITOA_BASE_H

int my_strlen(const char *str);
int my_strcmp(const char *s1, const char *s2);
void str_revert(char *str);
char *my_itoa_base(int n, char *s, const char *base);

#endif
