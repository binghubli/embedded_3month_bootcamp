#include <stdio.h>
#include "ring_buf.h"
#include "uart_sim.h"
#include "proto_parse.h"

#define RING_BUF_CAP 128
uint8_t ring_storage[RING_BUF_CAP];

//构造一帧完整协议数据
uint8_t make_test_frame(uint8_t payload_len, uint8_t *frame_out)
{
    size_t idx = 0;
    frame_out[idx++] = 0xAA;
    frame_out[idx++] = payload_len;
    for(uint8_t i = 0; i < payload_len; i++)
    {
        frame_out[idx++] = i + 1;
    }
    //CRC占位2字节
    frame_out[idx++] = 0x00;
    frame_out[idx++] = 0x00;
    return idx;
}

int main(void)
{
    RingBuf rb;
    ProtoParser parser;
    ring_buf_init(&rb, ring_storage, RING_BUF_CAP);
    proto_parser_init(&parser);

    //构造测试帧
    uint8_t frame[64];
    size_t frame_len = make_test_frame(10, frame);
    printf("原始协议帧总长度：%zu\n", frame_len);

    //UART模拟器随机分片送入环形缓冲（每次1~4字节）
    uart_sim_send_slice(&rb, frame, frame_len, 1, 4);

    //从环形缓冲区解析协议
    proto_parse_from_ring(&parser, &rb);

    //读取解析出的载荷
    uint8_t payload[128];
    size_t pay_len;
    if(proto_get_frame(&parser, payload, &pay_len) == 0)
    {
        printf("解析载荷数据：");
        for(size_t i = 0; i < pay_len; i++)
        {
            printf("%02X", payload[i]);
        }
        printf("\n");
    }
    return 0;
}