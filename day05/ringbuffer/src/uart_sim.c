#include "uart_sim.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void uart_sim_send_slice(RingBuf* rb, const uint8_t* raw_data, size_t data_len, size_t slice_min, size_t slice_max)
{
    if (raw_data == NULL || data_len == 0 || slice_min > slice_max)
        return;
    srand((unsigned)time(NULL));
    size_t pos = 0;
    while (pos < data_len)
    {
        // 随机分片长度
        size_t slice_len = slice_min + rand() % (slice_max - slice_min + 1);
        if (pos + slice_len > data_len)
            slice_len = data_len - pos;
        // 写入环形缓冲
        size_t write_cnt = ring_buf_write_burst(rb, raw_data + pos, slice_len);
        printf("[UART_SIM] 分片注入 %zu 字节，实际写入%zu\n", slice_len, write_cnt);
        pos += slice_len;
    }
}