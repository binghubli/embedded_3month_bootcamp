#include <stdio.h>
#include "fsm_test.h"

int main(void)
{
    test_fsm_normal_flow();
    test_fsm_error_flow();
    test_fsm_timeout_flow();
    return 0;
}