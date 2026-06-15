#include <stdio.h>
#include "mini_string.h"

int main(void)
{
    char str1[64] = "Hello, Bing";
    char str2[64];
    char overlap_buf[16] = "123456789";

    //基础函数测试
    printf("strlen:%zu\n", mini_strlen(str1));
    mini_strcpy(str2, str1);
    printf("strcpy:%s\n", str2);
    printf("strcmp:%d\n", mini_strcmp(str1,str2));

    //重叠内存测试
    mini_memmove(overlap_buf + 2, overlap_buf, 5);
    printf("memmove重叠结果:%s\n", overlap_buf);

    //========故意制造3类经典错误，用于GDB调试 ========

#if 1
    //错误1: 空指针接引用
    // char *p = NULL;
    // *p = 100;

    //错误2: 数组越界写栈
    int arr[4] = {1, 2, 3, 4};
    arr[10] = 999;

    //错误3: 修改.rodata 常量字符串
    char *str_const  = "read_only_str";
    str_const[0] = 'X';
#endif

    return 0;
}
