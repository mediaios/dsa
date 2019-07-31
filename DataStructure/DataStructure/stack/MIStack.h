//
//  MIStack.h
//  DataStructure
//
//  Created by mediaios on 2019/7/31.
//  Copyright © 2019 mediaios. All rights reserved.
//

#ifndef MIStack_h
#define MIStack_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_STACK_SIZE   100
typedef struct MIStackNode{
    int data;
    /***/
    struct MIStackNode *pre;
}MIStackNode;

typedef struct MIStack{
    int size;
    struct MIStackNode *top;
}MIStack;


MIStack * CreateEmptyStack(void);
int isStackEmpty(MIStack *stack);
int isStackFull(MIStack *stack);
int push(MIStack *stack,int data);
int pop(MIStack *stack,int *data);
int getTop(MIStack *stack,int *data);
void printStack(MIStack *stack);
void destory(MIStack *stack);

void test(void);

#endif /* MIStack_h */
