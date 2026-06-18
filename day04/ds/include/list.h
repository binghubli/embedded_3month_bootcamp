#ifndef LIST_H
#define LIST_H

#include <stddef.h>

// 单链表节点
typedef struct SingleNode
{
    int                data;
    struct SingleNode* next;
} SingleNode;

// 单链表操作
SingleNode* slist_create_node(int val);
void        slist_add_head(SingleNode** head, int val);
void        slist_add_tail(SingleNode** head, int val);
int         slist_del_node(SingleNode** head, int val);
int         slist_modify(SingleNode** head, int old_val, int new_val);
SingleNode* slist_find(SingleNode* head, int val);
void        slist_traverse(SingleNode* head);
void        slist_destroy(SingleNode** head);

// 双向链表节点
typedef struct DoubleNode
{
    int                data;
    struct DoubleNode* prev;
    struct DoubleNode* next;
} DoubleNode;

// 双向链表操作
DoubleNode* dlist_create_node(int val);
void        dlist_add_head(DoubleNode** head, int val);
void        dlist_add_tail(DoubleNode** head, int val);
int         dlist_del_node(DoubleNode** head, int val);
int         dlist_modify(DoubleNode* head, int old_val, int new_val);
DoubleNode* dlist_find(DoubleNode* head, int val);
void        dlist_traverse(DoubleNode* head);
void        dlist_destroy(DoubleNode** head);

#endif
