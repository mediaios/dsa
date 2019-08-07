//
//  MIQueue.h
//  DataStructure
//
//  Created by mediaios on 2019/7/18.
//  Copyright © 2019 mediaios. All rights reserved.
//

#ifndef MIQueue_h
#define MIQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_QUEUE_SIZE   100

typedef struct MIQueueNode
{
    int data;
    struct MIQueueNode *next;
}MIQueueNode;

typedef struct MIQueue
{
    int size;
    MIQueueNode *front;
    MIQueueNode *rear;
}MIQueue;


MIQueue *createQueue(void);
int inQueue(MIQueue *q,int data);
int  queueOut(MIQueue *queue,int *data);
int isQueueFull(MIQueue *q);
int isQueueEmpty(MIQueue *q);
void printQueue(MIQueue *queue);
void destoryQueue(MIQueue *queue);

void testQueue(void);



#endif /* MIQueue_h */
