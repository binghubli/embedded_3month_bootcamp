#include <stdio.h>
#include "crc_test.h"

int main(void)
{
    test_crc8();
    test_crc16_modbus();
    test_crc32();
    return 0;
}