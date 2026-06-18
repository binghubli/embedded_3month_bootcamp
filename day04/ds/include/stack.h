#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct StackNode
{
    int               data;
    struct StackNode* next;
} StackNode;

typedef struct
{
    StackNode* top;
} Stack;

void stack_init(Stack* stk);
int  stack_push(Stack* stk, int val);
int  stack_pop(Stack* stk, int* pval);
int  stack_top(Stack* stk, int* pval);
int  stack_empty(Stack* stk);
void stack_destroy(Stack* stk);

#endif
