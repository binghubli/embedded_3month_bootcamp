#include "crc_test.h"
#include "crc.h"
#include <stdio.h>
#include <string.h>

//标准测试字符串
static const uint8_t test_str[] = "123456789";
static const size_t test_len = sizeof(test_str) - 1;

void test_crc8(void)
{
    printf("==== 测试CRC8 ====\n");
    uint8_t crc8 = crc8_calc(test_str, test_len);
    printf("CRC8=0x%02X\n", crc8);
}

void test_crc16_modbus(void)
{
    printf("==== 测试CRC16 Modbus ====\n");
    uint16_t crc16 = crc16_calc(test_str, test_len);
    printf("CRC16=0x%04X\n", crc16);
}

void test_crc32(void)
{
    printf("==== 测试CRC32 ====\n");
    uint32_t crc32 = crc32_calc(test_str, test_len);
    printf("CRC32=0x%08X\n", crc32);
}