#ifndef CRC_H
#define CRC_H

#include <stdint.h>
#include <stddef.h>

//CRC8标准（0x07)
uint8_t crc8_calc(const uint8_t *data, size_t len);

//CRC16标准（0x8005)
uint16_t crc16_calc(const uint8_t *data, size_t len);

//CRC32标准
uint32_t crc32_calc(const uint8_t *data, size_t len);

#endif
