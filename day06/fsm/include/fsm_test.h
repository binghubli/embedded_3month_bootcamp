#ifndef FSM_TEST_H
#define FSM_TEST_H

#include "dev_fsm.h"

//三套测试用例
void test_fsm_normal_flow(void);    //正常流程: INIT -> IDLE -> WORKING  -> IDLE
void test_fsm_error_flow(void);     //错误流程: INIT -> IDLE -> ERR -> RECOVERY -> IDLE
void test_fsm_timeout_flow(void);   //超时流程: WORK超时/恢复超时

#endif
