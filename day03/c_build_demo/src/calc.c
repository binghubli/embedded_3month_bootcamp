#include "calc.h"

RetCode calc_add(int a, int b, int *res)
{
    if(res == NULL)
        return RET_NULL_PTR;
    *res = a + b;
    return RET_OK;
}

RetCode calc_sub(int a, int b, int *res)
{
    if(res == NULL)
        return RET_NULL_PTR;
    *res = a - b;
    return RET_OK;
}