
#include "bit_test.h"
#include "bitops.h"
#include <stdio.h>
#include <stddef.h>

void test_macro(void)
{
    printf("===== 测试寄存器位操作宏 =====\n");
    uint32_t reg = 0;
    SET_BIT(reg, 3);
    printf("SET_BIT3 reg=0x%08X\n", reg);
    CLEAR_BIT(reg,3);
    printf("CLEAR_BIT3 reg=0x%08X\n", reg);

    reg = 0;
    WRITE_FIELD(reg, 4, 3, 0x5);
    printf("WRITE_FIELD bit4~6=5 reg=0x%08X\n", reg);
    printf("READ_BIT5 = %u\n", READ_BIT(reg,5));
}

void test_bit_field(void)
{
    printf("\n===== 测试位域 =====\n");
    ByteBitField bf;
    bf.bit0 = 1;
    bf.bit1 = 0;
    bf.bit2_3 = 3;
    bf.high = 0xA;
    uint8_t *p = (uint8_t*)&bf;
    printf("位域整体字节:0x%02X\n", *p);
}

void test_endian_swap(void)
{
    printf("\n===== 测试大小端转换 =====\n");
    printf("本机是小端? %s\n", is_little_endian() ? "true" : "false");
    uint16_t u16 = 0x1234;
    uint16_t be16 = host_to_be16(u16);
    printf("host 0x%04X -> be16 0x%04X\n", u16, be16);

    uint32_t u32 = 0x11223344;
    uint32_t be32 = host_to_be32(u32);
    printf("host 0x%08X -> be32 0x%08X\n", u32, be32);
}

// 内存对齐测试
typedef struct AlignTest1 {
    uint8_t a;
    uint32_t b;
} AlignTest1;

#pragma pack(1)
typedef struct AlignTest2 {
    uint8_t a;
    uint32_t b;
} AlignTest2;
#pragma pack()

void test_struct_align(void)
{
    printf("\n===== 测试结构体内存对齐 =====\n");
    printf("默认对齐 AlignTest1 size=%zu\n", sizeof(AlignTest1));
    printf("pack(1)压缩 AlignTest2 size=%zu\n", sizeof(AlignTest2));
    printf("a偏移:%zu, b偏移:%zu\n", offsetof(AlignTest1,a), offsetof(AlignTest1,b));
}