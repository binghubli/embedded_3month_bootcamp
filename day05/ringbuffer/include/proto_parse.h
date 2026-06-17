#ifndef PROTO_PARSE_H
#define PROTO_PARSE_H

#include "ring_buf.h"
#include <stdint.h>
#include <stddef.h>

#define FRAME_HEAD 0xAA
#define FRAME_CRC_LEN 2

//帧解析状态机
typedef enum {
    WAIT_HEAD,
    WAIT_LEN,
    WAIT_PAYLOAD,
    WAIT_CRC
} ParseState;

typedef struct {
    ParseState state;
    uint8_t payload_len;
    size_t payload_idx;
    uint8_t payload_buf[128];
} ProtoParser;

//初始化解析器
void proto_parser_init(ProtoParser *parser);
//从环形缓冲区持续读取字节解析帧
void proto_parse_from_ring(ProtoParser *parser, RingBuf *rb);
//获取解析完成的一帧数据
int proto_get_frame(ProtoParser *parser, uint8_t *out, size_t *out_len);

#endif

