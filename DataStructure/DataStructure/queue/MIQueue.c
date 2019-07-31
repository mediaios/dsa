//
//  MIQueue.c
//  DataStructure
//
//  Created by mediaios on 2019/7/18.
//  Copyright © 2019 mediaios. All rights reserved.
//

#include "MIQueue.h"


MIQueue *createQueue()
{
    MIQueue *q = (MIQueue *)malloc(sizeof(MIQueue));
    if (!q) {
        printf("malloc memory error \n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

int inQueue(MIQueue *q,int data)
{
    assert(q);
    if (isQueueFull(q)) {
        printf("queu is full \n");
        return -1;
    }
    MIQueueNode *qNode = (MIQueueNode *)malloc(sizeof(MIQueueNode));
    if (qNode == NULL) {
        printf("malloc memory error \n");
        return -1;
    }
    qNode->data = data;
    qNode->next = NULL;
    if (isQueueEmpty(q)) {
        q->front = qNode;
        q->rear = qNode;
    }else{
        q->rear->next = qNode;
        q->rear = qNode;
    }
    q->size += 1;
    return 0;
}

int  queueOut(MIQueue *queue,int *data)
{
    assert(queue);
    if (isQueueEmpty(queue)) {
        printf("queue is empty !\n");
        return -1;
    }
    MIQueueNode *qNode = NULL;
    qNode = queue->front;
    *data = qNode->data;
    queue->front = queue->front->next;
    queue->size -= 1;
    
    if (isQueueEmpty(queue)) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    free(qNode);
    return 0;
    
}

int isQueueFull(MIQueue *q)
{
    assert(q);
    return (q->size == MAX_QUEUE_SIZE);
}

int isQueueEmpty(MIQueue *q)
{
    assert(q);
    return (q->size == 0);
}

void printQueue(MIQueue *queue)
{
    assert(queue);
    printf("queue size is: %d \n",queue->size);
    MIQueueNode *p = NULL;
    p = queue->front;
    while (p != NULL) {
        printf(" %d ",p->data);
        p =  p->next;
    }
    printf("\n");
}

void destoryQueue(MIQueue *queue)
{
    assert(queue);
    MIQueueNode *p = NULL;
    MIQueueNode *q = NULL;
    if (isQueueEmpty(queue) != 1) {
        q = p = queue->front;
        while (p != NULL) {
            queue->size -= 1;
            q = p->next;
            free(p);
            p = q;
        }
    }
    queue->front = NULL;
    queue->rear = NULL;
    free(queue);
    queue = NULL;
}


void testQueue()
{
    MIQueue *queue = NULL;
    int data;
    int i;
    int ret;
    queue = createQueue();
    ret = queueOut(queue,&data);
    if(ret == 0){
        printf("read success data is :%d\n",data);
    }else{
        printf("The queue is empty ,not havs data\n");
    }
    for(i=0;i<MAX_QUEUE_SIZE+5;i++){
        inQueue(queue,i*5+10);
    }
    printQueue(queue);
    destoryQueue(queue);
}

