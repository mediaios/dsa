//
//  MIStack.c
//  DataStructure
//
//  Created by mediaios on 2019/7/31.
//  Copyright © 2019 mediaios. All rights reserved.
//

#include "MIStack.h"


MIStack* CreateEmptyStack()
{
    MIStack *stack = NULL;
    stack = (MIStack *)malloc(sizeof(MIStack));
    if (stack == NULL) {
        printf("malloc memory error !\n");
        exit(-1);
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int isStackEmpty(MIStack *stack)
{
    assert(stack != NULL);
    return (stack->top == NULL);
}

int isStackFull(MIStack *stack)
{
    assert(stack != NULL);
    return (stack->size >= MAX_STACK_SIZE);
}

int push(MIStack *stack,int data)
{
    assert(stack != NULL);
    MIStackNode *p = NULL;
    if (isStackFull(stack)) {
        printf("The stack is full !\n");
        return -1;
    }
    p = (MIStackNode *)malloc(sizeof(MIStackNode));
    if (p == NULL) {
        printf("push melloc memory error !\n");
        return -1;
    }
    p->data = data;
    p->pre = NULL;
    p->pre = stack->top;
    stack->top = p;
    (stack->size)++;
    return 0;
}

int pop(MIStack *stack,int *data)
{
    assert(stack);
    if (isStackEmpty(stack)) {
        printf("The stack is empty !\n");
        return -1;
    }
    MIStackNode *p;
    p = stack->top;
    *data = p->data;
    stack->top = p->pre;
    (stack->size)--;
    free(p);
    p = NULL;
    return 0;
}

int getTop(MIStack *stack,int *data)
{
    assert(stack);
    if (isStackEmpty(stack)) {
        printf("The stack is empty !\n");
        return -1;
    }
    *data = stack->top->data;
    return 0;
}

void printStack(MIStack *stack)
{
    assert(stack);
    if (isStackEmpty(stack)) {
        printf("The stack is empty !\n");
        return;
    }
    
    MIStackNode *p= stack->top;
    while (p != NULL) {
        printf(" %d ",p->data);
        p = p->pre;
    }
    printf("\n");
}

void destory(MIStack *stack)
{
    assert(stack);
    if (isStackEmpty(stack)) {
        return;
    }
    MIStackNode *p,*q;
    p = q = stack->top;
    while (p != NULL) {
        q = p->pre;
        free(p);
        p = q;
    }
    free(stack);
    return;
}


void test(void)
{
    MIStack *stack = NULL;
    int i,data,ret;
    stack = CreateEmptyStack();
    for(i=0;i<50;i++){
        push(stack,i*5);
    }
    ret = getTop(stack,&data);
    if(ret == -1){
        printf("get data error !\n");
    }else{
        printf("get top data %d \n",data);
    }
    
    ret = pop(stack,&data);
    if (ret == -1) {
        printf("get data error !\n");
    }else{
        printf("pop top data %d \n",data);
    }
    
    printStack(stack);
}
