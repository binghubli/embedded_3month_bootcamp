#ifndef RING_BUF_H
#define RING_BUF_H

#include <stdint.h>
#include <stddef.h>

typedef struct
{
    uint8_t *buf;
    size_t cap;
    size_t rd;
    size_t wr;
} RingBuf;

//初始化环形缓冲区（外部数组）
void ring_buf_init(RingBuf *rb, uint8_t *buf, size_t buf_len);

//单字节写入
int ring_buf_write(RingBuf *rb, uint8_t dat);
//批量多字节写入
size_t ring_buf_write_burst(RingBuf *rb, const uint8_t *dat, size_t len);

//单字节读出
int ring_buf_read_byte(RingBuf *rb, uint8_t *out);
//批量多字节读出
size_t ring_buf_read_burst(RingBuf *rb, uint8_t *out, size_t len);

//状态判断
int ring_buf_empty(RingBuf *rb);
int ring_buf_full(RingBuf *rb);

//获取可读/可写字节数
size_t ring_buf_get_readable(RingBuf *rb);
size_t ring_buf_get_writable(RingBuf *rb);

#endif

