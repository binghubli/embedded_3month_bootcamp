#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

void queue_init(Queue *q);
int queue_enqueue(Queue *q, int val);
int queue_dequeue(Queue *q, int *val);
int queue_empty(Queue *q);
void queue_destroy(Queue *q);

#endif

