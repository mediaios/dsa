//
//  MISeqList.c
//  DataStructure
//
//  Created by mediaios on 2019/7/18.
//  Copyright © 2019 mediaios. All rights reserved.
//

#include "MISeqList.h"

SeqList SeqListInit()
{
    SeqList L;
    L.last = 0;  // 顺序表长度为0
    return L;
}



/**
 在顺序表L中查找元素X，若查找成功，则返回它的位置，否则返回-1

 @param L 顺序表
 @param x 要查找的元素
 @return 如果找到，则返回位置，否则返回-1
 */
int SeqListLocate(SeqList L,int x)
{
    int i = 1;
    while (i < L.last && L.data[i-1] != x) {
        i++;
    }
    return i < L.last ? i : -1;
}

int IsEmptyList(SeqList L)
{
    return L.last == 0 ? TRUE : FALSE;
}

SeqList SeqListInsert(SeqList L,int i, int x)
{
    int j;
    if (L.last == MAXSiIZE) {
        printf("表满了，表最多存储100个元素\n");
        exit(0);
    }
    if (i < 1 || i > L.last+1) {
        printf("插入位置错误\n");
        exit(0);
    }
    for (j = L.last - 1; j >= i-1; j--) {
        L.data[j+1] = L.data[j];
    }
    L.data[i-1] = x;
    L.last++;
    return L;
}

void ShowData(SeqList L)
{
    for (int i = 0; i < L.last;i++) {
        printf("%d\t",L.data[i]);
    }
    printf("\n");
}
SeqList SeqListDelete(SeqList L,int i)
{
    if (i < 1 || i > L.last) {
        printf("位置非法\n");
        exit(0);
    }
    int j;
    for (j = i; j < L.last -1; j++) {
        L.data[j-1] = L.data[j];
    }
    L.last--;
    return L;
}

// 合并非递减有序顺序表
SeqList SeqListMerge(SeqList Sla, SeqList Slb)
{
    // 将非递减有序的顺序表Sla和Slb合并成一个新的顺序表Slc，Slc也是非递减有序的
    // 初始化
    SeqList Slc;
    Slc.last = 0;
    int i = 0, j = 0, k = -1;
    while(i < Sla.last && j < Slb.last)     // Sla和Slb均非空
    {
        if(Sla.data[i] <= Slb.data[j])
        {
            Slc.data[++k] = Sla.data[i++];  // Sla中元素插入Slc
        }
        else
        {
            Slc.data[++k] = Slb.data[j++];  // Slb中元素插入Slc
        }
    }
    while(i < Sla.last)
    {
        Slc.data[++k] = Sla.data[i++];      // Slb已空，将Sla表的剩余部分复制到新表
    }
    while(j < Slb.last)
    {
        Slc.data[++k] = Slb.data[j++];      // Sla已空，将Slb表的剩余部分复制到新表
    }
    Slc.last = k + 1;
    return (Slc);
}
