#include "fsm_test.h"
#include <stdio.h>

void test_fsm_normal_flow(void)
{
    printf("==== 测试1:正常状态流程 ====\n");
    DevFsmCtx ctx;
    dev_switch_fsm_init(&ctx);
    dev_switch_fsm_run(&ctx, EV_POWER_ON);
    dev_switch_fsm_run(&ctx, EV_START);
    dev_switch_fsm_run(&ctx, EV_STOP);
    dev_switch_fsm_run(&ctx, EV_STOP);
    printf("====正常流程测试结束====\n\n");
}

void test_fsm_error_flow(void)
{
    printf("==== 测试2:异常流状态恢复流程====\n");
    DevFsmCtx ctx;
    dev_switch_fsm_init(&ctx);
    dev_switch_fsm_run(&ctx, EV_POWER_ON);
    dev_switch_fsm_run(&ctx, EV_START);
    dev_switch_fsm_run(&ctx, EV_ERR);   // 触发故障
    dev_switch_fsm_run(&ctx, EV_RESET); // 复位恢复
    dev_switch_fsm_run(&ctx, EV_POWER_ON);
    printf("====异常恢复流程测试结束====\n\n");
}

void test_fsm_timeout_flow(void)
{
    printf("==== 测试3:超时故障流程====\n");
    DevFsmCtx ctx;
    dev_switch_fsm_init(&ctx);
    dev_switch_fsm_run(&ctx, EV_POWER_ON);
    dev_switch_fsm_run(&ctx, EV_START);
    dev_switch_fsm_run(&ctx, EV_TIMEOUT); // 触发超时
    dev_switch_fsm_run(&ctx, EV_RESET);   // 复位恢复
    dev_switch_fsm_run(&ctx, EV_TIMEOUT); // 恢复阶段再次超时
    printf("====超时故障测试结束====\n\n");
}