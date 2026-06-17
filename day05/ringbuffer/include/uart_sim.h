#ifndef UART_SIM_H
#define UART_SIM_H 

#include "ring_buf.h"
#include <stdint.h>
#include <stddef.h>

//模拟串口随机分片送入ringbuffer
//raw_data: 完整原始数据. data_len总长
//slice_min/slice_max:每次分片最小/最大字节
void uart_sim_send_slice(RingBuf *rb, const uint8_t *raw_data, size_t data_len, 
    size_t slice_min, size_t slice_max);

#endif
