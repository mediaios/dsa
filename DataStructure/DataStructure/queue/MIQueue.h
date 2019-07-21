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


typedef struct MINode
{
    char *data;
    struct MINode *next;
}MINode;

typedef struct MIQueue
{
    int size;
    MINode *front;
    MINode *rear;
}MIQueue;

MIQueue *CreateQueue();
int isFull(MIQueue *q);
void Add(MIQueue *q, MINode *node);
int IsEmpty(MIQueue *q);
void PrintQueue(MIQueue *q);



#endif /* MIQueue_h */
