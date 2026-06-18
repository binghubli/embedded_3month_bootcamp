#include "proto_parse.h"
#include <stdio.h>

void proto_parser_init(ProtoParser* parser)
{
    parser->state       = WAIT_HEAD;
    parser->payload_len = 0;
    parser->payload_idx = 0;
}

void proto_parse_from_ring(ProtoParser* parser, RingBuf* rb)
{
    uint8_t dat;
    while (!ring_buf_empty(rb))
    {
        if (ring_buf_read_byte(rb, &dat) != 0)
            break;
        switch (parser->state)
        {
        case WAIT_HEAD:
            if (dat == FRAME_HEAD)
            {
                parser->state = WAIT_LEN;
            }
            break;
        case WAIT_LEN:
            parser->payload_len = dat;
            parser->payload_idx = 0;
            parser->state       = WAIT_PAYLOAD;
            break;
        case WAIT_PAYLOAD:
            parser->payload_buf[parser->payload_idx++] = dat;
            if (parser->payload_idx >= parser->payload_len)
            {
                parser->state = WAIT_CRC;
            }
            break;
        case WAIT_CRC:
            // CRC占位,读完2字节即一帧完成，重置状态机
            static uint8_t crc_cnt = 0;
            crc_cnt++;
            if (crc_cnt >= FRAME_CRC_LEN)
            {
                crc_cnt       = 0;
                parser->state = WAIT_HEAD;
                printf("[PROTO] 解析完整帧，载荷长度：%d\n", parser->payload_len);
            }
            break;
        default:
            parser->state = WAIT_HEAD;
            break;
        }
    }
}

int proto_get_frame(ProtoParser* parser, uint8_t* out, size_t* out_len)
{
    if (parser->state != WAIT_HEAD)
        return -1;
    if (out == NULL || out_len == NULL)
        return -1;
    *out_len = parser->payload_len;
    for (size_t i = 0; i < *out_len; i++)
    {
        out[i] = parser->payload_buf[i];
    }
    return 0;
}