#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void stack_init(Stack* stk)
{
    if (!stk)
        return;
    stk->top = NULL;
}

int stack_push(Stack* stk, int val)
{
    if (!stk)
        return -1;
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (!node)
        return -1;
    node->data = val;
    node->next = stk->top;
    stk->top   = node;
    return 0;
}

int stack_pop(Stack* stk, int* pval)
{
    if (!stk || stack_empty(stk) || !pval)
        return -1;
    StackNode* tmp = stk->top;
    *pval          = tmp->data;
    stk->top       = tmp->next;
    free(tmp);
    return 0;
}

int stack_top(Stack* stk, int* pval)
{
    if (!stk || stack_empty(stk) || !pval)
        return -1;
    *pval = stk->top->data;
    return 0;
}

int stack_empty(Stack* stk) { return (stk == NULL || stk->top == NULL) ? 1 : 0; }

void stack_destroy(Stack* stk)
{
    if (!stk)
        return;
    int tmp;
    while (!stack_empty(stk))
    {
        stack_pop(stk, &tmp);
    }
}