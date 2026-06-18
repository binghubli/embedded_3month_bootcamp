#include "dev_fsm.h"
#include <stdio.h>
#include <string.h>

// ============== 公共工具 ==============
void fsm_tick_inc(DevFsmCtx *ctx)
{
    if(!ctx) return;
    ctx -> tick_cnt++;
}

bool fsm_is_timeout(DevFsmCtx *ctx, uint32_t threshold)
{
    if(!ctx) return false;
    return ctx -> tick_cnt >= threshold;
}

// ============== Switch-Case 实现状态机 ==============
void dev_switch_fsm_init(DevFsmCtx *ctx)
{
    memset(ctx, 0, sizeof(DevFsmCtx));
    ctx -> cur_state = FSM_INIT;
    printf("[SWITCH FSM] 初始化完成， 进入INIT\n");
}

static void handle_init(DevFsmCtx *ctx, DevEvent evt)
{
    switch(evt)
    {
        case EV_POWER_ON:
            ctx -> cur_state = FSM_IDLE;
            ctx -> tick_cnt = 0;
            printf("[SWITCH] INIT -> IDLE(上电就绪）\n");
            break;
        default:
            printf("[SWITCH] INIT -> INIT(无效事件)\n");
            break;
    }
 
}

static void handle_idle(DevFsmCtx *ctx, DevEvent evt)
{
    switch(evt)
    {
    case EV_START:
        ctx -> cur_state = FSM_WORKING;
        ctx -> tick_cnt = 0;
        printf("[SWITCH] IDLE -> WORKING(开始工作)\n");
        break;
    case EV_ERR:
        ctx -> cur_state = FSM_ERROR;
        ctx -> error_flag = true;
        ctx -> tick_cnt = 0;
        printf("[SWITCH] IDLE -> ERROR(空闲异常)\n");
        break;
    default:
        break;
    }
}

static void handle_working(DevFsmCtx *ctx, DevEvent evt)
{
    switch(evt)
    {
    case EV_STOP:
        ctx -> cur_state = FSM_IDLE;
        ctx -> tick_cnt = 0;
        printf("[SWITCH] WORKING -> IDLE(停止工作)\n");
        break;
    case EV_ERR:
        ctx -> cur_state = FSM_ERROR;
        ctx -> error_flag = true;
        ctx -> tick_cnt = 0;
        printf("[SWITCH] WORKING -> ERROR(工作异常)\n");
        break;
    default:
        break;
    }
}

static void handle_error(DevFsmCtx *ctx, DevEvent evt)
{
    switch(evt)
    {
        case EV_RESET:
            ctx -> cur_state = FSM_RECOVERY;
            ctx -> tick_cnt = 0;
            printf("[SWITCH] ERROR -> RECOVERY(故障恢复)\n");
            break;
        default:
            break;
    }
}

static void handle_recovery(DevFsmCtx *ctx, DevEvent evt)
{
    switch(evt)
    {
        case EV_POWER_ON:
            ctx -> error_flag = false;
            ctx -> cur_state = FSM_IDLE;
            ctx -> tick_cnt = 0;
            printf("[SWITCH] RECOVERY -> IDLE(故障恢复完成)\n");
            break;
        case EV_TIMEOUT:
            ctx -> cur_state = FSM_ERROR;
            printf("[SWITCH] RECOVERY -> ERROR(故障恢复超时)\n");
            break;
        default:
            break;
    }
}

void dev_switch_fsm_run(DevFsmCtx *ctx, DevEvent evt)
{
    if(!ctx) return;
    fsm_tick_inc(ctx);
    switch(ctx -> cur_state)
    {
        case FSM_INIT:
            handle_init(ctx, evt);
            break;
        case FSM_IDLE:
            handle_idle(ctx, evt);
            break;
        case FSM_WORKING:
            handle_working(ctx, evt);
            break;
        case FSM_ERROR:
            handle_error(ctx, evt);
            break;
        case FSM_RECOVERY:
            handle_recovery(ctx, evt);
            break;
        default:
            break;
    }
}

// ============== 表驱动状态机实现 ==============
//各状态处理函数
static void state_init(DevFsmCtx *ctx, DevEvent evt);
static void state_idle(DevFsmCtx *ctx, DevEvent evt);
static void state_working(DevFsmCtx *ctx, DevEvent evt);
static void state_error(DevFsmCtx *ctx, DevEvent evt);
static void state_recovery(DevFsmCtx *ctx, DevEvent evt);

//状态转换表
static const FsmTableItem fsm_table[] =
{
    {FSM_INIT,    EV_POWER_ON, FSM_IDLE,    state_init},
    {FSM_IDLE,    EV_START,    FSM_WORKING, state_idle},
    {FSM_IDLE,    EV_ERR,      FSM_ERROR,   state_idle},
    {FSM_WORKING, EV_STOP,     FSM_IDLE,    state_working},
    {FSM_WORKING, EV_ERR,      FSM_ERROR,   state_working},
    {FSM_WORKING, EV_TIMEOUT,  FSM_ERROR,   state_working},
    {FSM_ERROR,   EV_RESET,    FSM_RECOVERY,state_error},
    {FSM_RECOVERY,EV_POWER_ON, FSM_IDLE,    state_recovery},
    {FSM_RECOVERY,EV_TIMEOUT,  FSM_ERROR,   state_recovery},
};
#define FSM_TABLE_LEN (sizeof(fsm_table)/sizeof(FsmTableItem))

void dev_table_fsm_init(DevFsmCtx *ctx)
{
    memset(ctx, 0, sizeof(DevFsmCtx));
    ctx -> cur_state = FSM_INIT;
    printf("[SWITCH FSM] 初始化完成， 进入INIT\n");
}

void dev_table_fsm_run(DevFsmCtx *ctx, DevEvent evt)
{
    if(!ctx) return;
    fsm_tick_inc(ctx);
    //查表匹配当前状态
    for(int i = 0; i < FSM_TABLE_LEN; i++)
    {
        const FsmTableItem *item = &fsm_table[i];
        if(item -> state == ctx -> cur_state && item -> evt == evt)
        {
            if(item -> handler)
            {
                item -> handler(ctx, evt);
            }
            ctx -> cur_state = item -> next_state;
            return;
        }
        printf("[TABLE FSM] 当前状态%d 无法匹配事件%d\n", ctx -> cur_state, evt);

    }
}

//表驱动状态处理函数
static void state_init(DevFsmCtx *ctx, DevEvent evt)
{
    ctx -> tick_cnt = 0;
    printf("[TABLE FSM] INIT -> IDLE(上电就绪)\n");
}

static void state_idle(DevFsmCtx *ctx, DevEvent evt)
{
    ctx -> tick_cnt = 0;
    if(evt == EV_START) printf("[TABLE FSM] IDLE -> WORKING(开始工作)\n");
    if(evt == EV_ERR) {printf("[TABLE FSM] IDLE -> ERROR(空闲异常)\n");}
}

static void state_working(DevFsmCtx *ctx, DevEvent evt)
{
    ctx -> tick_cnt = 0;
    if(evt == EV_STOP) {printf("[TABLE FSM] WORKING -> IDLE(停止工作)\n");}
    if(evt == EV_ERR) {printf("[TABLE FSM] WORKING -> ERROR(工作异常)\n");}
    if(evt == EV_TIMEOUT) {printf("[TABLE FSM] WORKING -> ERROR(工作超时)\n");}
}

static void state_error(DevFsmCtx *ctx, DevEvent evt)
{
    ctx -> tick_cnt = 0;
    if(evt == EV_RESET) {printf("[TABLE FSM] ERROR -> RECOVERY(故障恢复)\n");}
}

static void state_recovery(DevFsmCtx *ctx, DevEvent evt)
{
    ctx -> tick_cnt = 0;
    if(evt == EV_POWER_ON) {printf("[TABLE FSM] RECOVERY -> IDLE(故障恢复完成)\n");}
    if(evt == EV_TIMEOUT) {printf("[TABLE FSM] RECOVERY -> ERROR(故障恢复超时)\n");}
}

