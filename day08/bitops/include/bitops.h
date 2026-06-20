#ifndef BITOPS_H
#define BITOPS_H

#include <stdint.h>
#include <stdbool.h>

//============= 寄存器位操作宏（无副作用）=============
// 置1指定位
#define SET_BIT(reg, bit)       ((reg) |= (1U << (bit)))
// 置0指定位
#define CLEAR_BIT(reg, bit)     ((reg) &= ~(1U << (bit)))
// 读取指定位，返回0/1
#define READ_BIT(reg, bit)      (((reg) >> (bit)) & 1U)
// 写入多bit域: val写入start_bit开始，width位
#define WRITE_FIELD(reg, start_bit, width, val) \
do {\
    uint32_t mask = ((1U << (width)) - 1U) << (start_bit); \
    (reg) = ((reg) & ~mask) | (((val) << (start_bit)) & mask);\
} while(0);

//============= 位域示例结构体 =============
typedef struct {
    uint8_t bit0 : 1;
    uint8_t bit1 : 1;
    uint8_t bit2_3: 2;
    uint8_t high : 4;
} ByteBitField;

//============== 大小端转换函数 ==============
uint16_t host_to_be16(uint16_t val);
uint32_t host_to_be32(uint32_t val);
uint16_t be16_to_host(uint16_t val);
uint32_t be32_to_host(uint32_t val);

//判断当前机器是否大小端
bool is_little_endian(void);

#endif

