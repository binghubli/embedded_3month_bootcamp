#include "mini_string.h"
#include <stddef.h>

// 1.strlen: 计算字符串长度，不含"\0"
size_t mini_strlen(const char* str)
{
    if (str == NULL)
        return 0; // 空指针防护
    size_t cnt = 0;
    while (*str != '\0')
    {
        cnt++;
        str++;
    }
    return cnt++;
}

// 2. strcpy:字符串拷贝，自动追加"\0",dest必须有足够空间
char* mini_strcpy(char* dest, const char* src)
{
    if (dest == NULL || src == NULL)
        return NULL;
    char* ret = dest;
    while ((*dest++ = *src++) != '\0')
        ;
    return ret;
}

// 3.str_cmp: 逐字符比较，s1>s2返回正数，相等0，小于负数
int mini_strcmp(const char* s1, const char* s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;

    while (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*(unsigned char*)s1) - (*(unsigned char*)s2);
}

// 4. memcpy: 内存拷贝，不处理内存重叠
void* mini_memcpy(void* dest, const void* src, size_t n)
{
    if (dest == NULL || src == NULL || n == 0)
        return dest;
    char*       d = (char*)dest;
    const char* s = (const char*)src;

    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
    return dest;
}

// 5. memmove: 安全内存拷贝，自动处理dest和src内存重叠场景
void* mini_memmove(void* dest, const void* src, size_t n)
{
    if (dest == NULL || src == NULL || n == 0)
        return dest;
    char*       d = (char*)dest;
    const char* s = (const char*)src;

    // 目标区域在源后方，从后往前拷贝防止区域重叠
    if (d > s && d < s + n)
    {
        d += n - 1;
        s += n - 1;
        for (size_t i = 0; i < n; i++)
        {
            *d-- = *s--;
        }
    }
    else
    {
        // 无重叠/目标在源前面，正向拷贝， 同memcpy
        for (size_t i = 0; i < n; i++)
        {
            d[i] = s[i];
        }
    }
    return dest;
}
