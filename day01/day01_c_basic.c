#include <stdio.h>
#include <string.h>

//===========数组============//
void test_array(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len     = sizeof(arr) / sizeof(arr[0]);

    int sum = 0, max = arr[0], min = arr[0], cnt_odd = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] % 2)
            cnt_odd++;
    }
    printf("%d,%d,%d,%d", sum, max, min, cnt_odd);
}

//===========指针============//
void test_pointer(void)
{
    int  a      = 100;
    int* p      = &a;
    int  arr[5] = {10, 20, 30, 40, 50};
    int* parr   = arr;

    printf("变量a值:%d, 指针p取值:%d\n", a, *p);
    printf("parr[2]=%d,  *(parr+2)=%d\n", parr[2], *(parr + 2));
}

int main(void)
{
    test_array();
    test_pointer();
}