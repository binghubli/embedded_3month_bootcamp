#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// ======== 单链表 ========
SingleNode* slist_create_node(int val)
{
    SingleNode *node = (SingleNode*)malloc(sizeof(SingleNode));
    if(!node) return NULL;
    node->data = val;
    node->next = NULL;
    return node;
}

//头插
void slist_add_head(SingleNode **head, int val)
{
    if(!head) return;
    SingleNode *new_node = slist_create_node(val);
    if(!new_node) return;
    new_node -> next = *head;
    *head = new_node;
}

//尾插
void slist_add_tail(SingleNode **head, int val)
{
    if(!head) return;
    SingleNode *new_node = slist_create_node(val);
    if(!new_node) return;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    SingleNode *p = *head;
    while (p->next) p = p->next;
    p->next = new_node;
}

//删除指定节点
int slist_del_node(SingleNode **head, int val)
{
    if(!head || *head == NULL) return -1;

    SingleNode *p = *head, *pre = NULL;
    while (p && p->data != val)
    {
        pre = p;
        p = p -> next;
    }
    if(!p) return -1;

    if(pre == NULL)
        *head = p -> next;
    else
        pre->next = p->next;
    
    free(p);
    return 0;
}

//修改值
int slist_modify(SingleNode **head, int old_val, int new_val)
{
    SingleNode *p = slist_find(*head, old_val);
    if(!p) return -1;
    p -> data = new_val;
    return 0;
}

SingleNode* slist_find(SingleNode *head, int val)
{
    SingleNode *p = head;
    while(p)
    {
        if(p -> data == val)
            return p;
        p = p -> next;
    }

    return NULL;
}

//遍历
void slist_traverse(SingleNode *head)
{
    SingleNode *p = head;
    while(p)
    {
        printf("%d", p -> data);
        p = p -> next;
    }
    printf("\n");
}

//销毁整个链表（释放全部内存）
void slist_destroy(SingleNode **head)
{
    if(!head) return;
    SingleNode *q = NULL;
    SingleNode *p = *head;
    while(p)
    {
        q = p -> next;
        free(p);
        p = q;
    }
    *head = NULL;
}

// ========= 双向链表 =========
DoubleNode* dlist_create_node(int val)
{
    DoubleNode *node = (DoubleNode*)malloc(sizeof(DoubleNode*));
    node -> data = val;
    node -> prev = NULL;
    node -> next = NULL;
    return node;
}

void dlist_add_head(DoubleNode **head, int val)
{
    if(!head) return;
    DoubleNode *new_node = dlist_create_node(val);
    if(!new_node) return;
    
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    else
    {
        (*head) -> prev = new_node;
        new_node -> next = *head;
        *head = new_node;
    }
}

void dlist_add_tail(DoubleNode **head, int val)
{
    if(!head) return;
    DoubleNode *new_node = dlist_create_node(val);
    if(!new_node) return;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    DoubleNode *p = *head;
    while(p -> next) p = p -> next;
    p -> next = new_node;
    new_node -> prev = p;
}

int dlist_del_node(DoubleNode **head, int val)
{
    if(!head || *head == NULL) return -1;
    DoubleNode *p = dlist_find(*head ,val);
    if(!p) return -1;

    if(p -> prev)
        p -> prev -> next = p -> next;
    else
        *head = p -> next;

    free(p);
    return 0;
}

DoubleNode* dlist_find(DoubleNode *head, int val)
{
    DoubleNode *p = head;
    while(p)
    {
        if(p -> data == val)
        {
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

int dlist_modify(DoubleNode *head, int old_val, int new_val)
{
    DoubleNode *p = dlist_find(head, old_val);
    if(!p) return -1;
    p -> data = new_val;
    return 0;
}

void dlist_traverse(DoubleNode *head)
{
    DoubleNode *p = head;
    while(p -> next)
    {
        printf("%d", p -> data);
        p = p -> next;
    }
    printf("\n");
}

void dlist_destroy(DoubleNode **head)
{
    if(!head) return;
    DoubleNode *p = *head, *q;
    while(p)
    {
        q = p -> next;
        free(p);
        p = q;
    }
    *head = NULL;
}