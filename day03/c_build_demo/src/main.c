#include "calc.h"
#include "log.h"
#include <stdio.h>

int main(void)
{
    int ret;
    int val;

    log_info("Program start");

    ret = calc_add(10, 20, &val);
    if(ret == RET_OK)
    {
        printf("10 + 20 = %d\n", val);
    }
    else
    {
        log_error("calc_add failed");
    }

    ret = calc_sub(50, 15, &val);
        if(ret == RET_OK)
    {
        printf("50 - 15 = %d\n", val);
    }
    else
    {
        log_error("calc_sub failed");
    }

    log_info("Program end");
    return 0;
}