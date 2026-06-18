#ifndef DEV_FSM_H
#define DEV_FSM_H

#include <stdint.h>
#include <stdbool.h>

// 设备状态枚举
typedef enum
{
    FSM_INIT,
    FSM_IDLE,
    FSM_WORKING,
    FSM_ERROR,
    FSM_RECOVERY,
    FSM_STATE_MAX
} DevState;

// 触发事件枚举
typedef enum
{
    EV_POWER_ON,
    EV_START,
    EV_STOP,
    EV_ERR,
    EV_TIMEOUT,
    EV_RESET,
    EV_MAX
} DevEvent;

// FSM上下文: 保存状态、计时、错误标记
typedef struct
{
    DevState cur_state;
    uint32_t tick_cnt; // 计时用于超时判断
    bool     error_flag;
} DevFsmCtx;

// ======================Switch分支状态机 API======================
void dev_switch_fsm_init(DevFsmCtx* ctx);
void dev_switch_fsm_run(DevFsmCtx* ctx, DevEvent evt);

// ======================表驱动状态机 API======================
// 状态处理函数原型
typedef void (*StateHandler)(DevFsmCtx* ctx, DevEvent evt);
// 状态转换表项
typedef struct
{
    DevState     state;
    DevEvent     evt;
    DevState     next_state;
    StateHandler handler;
} FsmTableItem;

void dev_table_fsm_init(DevFsmCtx* ctx);
void dev_table_fsm_run(DevFsmCtx* ctx, DevEvent evt);

// 公共工具
void fsm_tick_inc(DevFsmCtx* ctx);
bool fsm_is_timeout(DevFsmCtx* ctx, uint32_t threshold);

#endif