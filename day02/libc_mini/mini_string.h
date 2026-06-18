#ifndef MINI_STRING_H
#define MINI_STRING_H

#include <stddef.h>

size_t mini_strlen(const char* str);
int    mini_strcmp(const char* s1, const char* s2);
char*  mini_strcpy(char* dest, const char* src);
void*  mini_memcpy(void* dest, const void* src, size_t n);
void*  mini_memmove(void* dest, const void* src, size_t n);

#endif
