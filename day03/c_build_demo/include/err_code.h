#ifndef ERR_CODE_H
#define ERR_CODE_H

typedef enum
{
    RET_OK        = 0,  // 正常
    RET_PARAM_ERR = -1, // 参数错误
    RET_NULL_PTR  = -2, // 空指针
    RET_OVERFLOW  = -3, // 溢出
    RET_UNKNOWN   = -4  // 未知错误
} RetCode;

#endif