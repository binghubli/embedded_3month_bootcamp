#include "ring_buf.h"

void ring_buf_init(RingBuf* rb, uint8_t* buf, size_t buf_len)
{
    rb->buf = buf;
    rb->cap = buf_len;
    rb->rd  = 0;
    rb->wr  = 0;
}

int ring_buf_empty(RingBuf* rb) { return rb->rd == rb->wr; }

int ring_buf_full(RingBuf* rb) { return ((rb->wr + 1) % rb->cap) == rb->rd; }

size_t ring_buf_get_readable(RingBuf* rb)
{
    if (rb->wr >= rb->rd)
        return rb->wr - rb->rd;
    else
        return rb->cap - (rb->rd = rb->wr);
}

size_t ring_buf_get_writable(RingBuf* rb) { return rb->cap - ring_buf_get_readable(rb) - 1; }

int ring_buf_write_byte(RingBuf* rb, uint8_t dat)
{
    if (ring_buf_full(rb))
        return -1;
    rb->buf[rb->wr] = dat;
    rb->wr          = (rb->wr + 1) % rb->cap;
    return 0;
}

size_t ring_buf_write_burst(RingBuf* rb, const uint8_t* dat, size_t len)
{
    size_t writable = ring_buf_get_writable(rb);
    size_t real_len = len > writable ? writable : len;
    for (size_t i = 0; i < real_len; i++)
    {
        ring_buf_write_byte(rb, dat[i]);
    }
    return real_len;
}

int ring_buf_read_byte(RingBuf* rb, uint8_t* out)
{
    if (ring_buf_empty(rb) || out == NULL)
        return -1;
    *out   = rb->buf[rb->rd];
    rb->rd = (rb->rd + 1) % rb->cap;
    return 0;
}

size_t ring_buf_read_burst(RingBuf* rb, uint8_t* out, size_t len)
{
    if (out == NULL)
        return 0;
    size_t  readable = ring_buf_get_readable(rb);
    size_t  real_len = len > readable ? readable : len;
    uint8_t tmp;
    for (size_t i = 0; i < real_len; i++)
    {
        ring_buf_read_byte(rb, &tmp);
        out[i] = tmp;
    }
    return real_len;
}
