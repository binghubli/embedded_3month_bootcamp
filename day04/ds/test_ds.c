#include <stdio.h>
#include "list.h"
#include "stack.h"
#include "queue.h"

//测试单链表
void test_slist(void)
{
    printf("==== 测试单链表 ====\n");
    SingleNode *head = NULL;
    slist_add_head(&head, 1);
    slist_add_head(&head, 2);
    slist_add_head(&head, 3);
    slist_add_tail(&head, 4);
    slist_add_tail(&head, 5);
    printf("遍历：");
    slist_traverse(head);

    slist_modify(&head, 2, 99);
    printf("修改后：");
    slist_traverse(head);

    slist_del_node(&head, 99);
    printf("删除后：");
    slist_traverse(head);

    slist_destroy(&head);
}

//测试栈
void test_stack(void)
{
    printf("==== 测试栈 ====\n");
    Stack stk;
    stack_init(&stk);
    
    stack_push(&stk, 100);
    stack_push(&stk, 200);
    stack_push(&stk, 300);

    int val;
    while(!stack_empty(&stk))
    {
        stack_pop(&stk, &val);
        printf("%d ", val);
    }
    printf("\n");

    stack_destroy(&stk);
}

//测试队列
void test_queue(void)
{
    printf("==== 测试队列 ====\n");
    Queue q;
    queue_init(&q);

    queue_enqueue(&q, 11);
    queue_enqueue(&q, 22);
    queue_enqueue(&q, 33);

    int val;
    while(!queue_empty(&q))
    {
        queue_dequeue(&q, &val);
        printf("%d ", val);
    }
    printf("\n");

    queue_destroy(&q);
}

int main(void)
{
    test_slist();
    test_stack();
    test_queue();
    return 0;
}