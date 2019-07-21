//
//  MIQueue.c
//  DataStructure
//
//  Created by mediaios on 2019/7/18.
//  Copyright © 2019 mediaios. All rights reserved.
//

#include "MIQueue.h"

#define MAXSIZE 100

MIQueue *CreateQueue()
{
    MIQueue *q = (MIQueue *)malloc(sizeof(MIQueue));
    if (!q) {
        printf("内存空间不足\n");
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

int isFull(MIQueue *q)
{
    return (q->size == MAXSIZE);
}

void Add(MIQueue *q, MINode *node)
{
    if (isFull(q)) {
        printf("队列已满\n");
        return;
    }
    
}

int IsEmpty(MIQueue *q)
{
    return 0;
}

void PrintQueue(MIQueue *q)
{
    
}

