#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void queue_init(Queue *q)
{
    if(!q) return;
    q -> front = NULL;
    q -> rear = NULL;
}

int queue_enqueue(Queue *q, int val)
{
    if(!q) return -1;
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    if(!node) return -1;
    node -> data = val;
    node -> next = NULL;

    if(queue_empty(q))
    {
        q -> front = node;
        q -> rear = node;
    }
    else
    {
        q -> rear -> next = node;
        q -> rear = node;
    }
    return 0;
}

int queue_dequeue(Queue *q, int *pval)
{
    if(!q || queue_empty(q) || !pval) return -1;
    QueueNode *tmp = q -> front;
    *pval = tmp -> data;

    if(q -> front == q -> rear)
    {
        q -> front = NULL;
        q -> rear = NULL;
    }
    else
    {
        q -> front = q -> front -> next;
    }
    free(tmp);
    return 0;
}

int queue_empty(Queue *q)
{
    return (q == NULL || q -> front == NULL) ? 1 : 0;
}

void queue_destroy(Queue *q)
{
    if(!q) return;
    int tmp;
    while(!queue_empty(q))
    {
        queue_dequeue(q, &tmp);
    }
}