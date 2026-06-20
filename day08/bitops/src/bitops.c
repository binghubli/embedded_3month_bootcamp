#include "bitops.h"

bool is_little_endian(void)
{
    union {
        uint16_t u16;
        uint8_t u8[2];
    } un = {0x0102};
    return un.u8[0] == 0x02;
}

uint16_t host_to_be16(uint16_t val)
{
    if(is_little_endian())
        return (val >> 8 | val << 8);  //交换高低字节
    return val;
}

uint32_t host_to_be32(uint32_t val)
{
    if(!is_little_endian())
        return val;
    return ((val &0xFF000000U) >> 24)
        |  ((val &0x00FF0000U) >>  8)
        |  ((val &0x0000FF00U) <<  8)
        |  ((val &0x000000FFU) << 24);
}

uint16_t be16_to_host(uint16_t val)
{
    return host_to_be16(val);
}

uint32_t be32_to_host(uint32_t val)
{
    return host_to_be32(val);
}



