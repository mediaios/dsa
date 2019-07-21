//
//  MISeqList.h
//  DataStructure
//
//  Created by mediaios on 2019/7/18.
//  Copyright © 2019 mediaios. All rights reserved.
//

#ifndef MISeqList_h
#define MISeqList_h

#include <stdio.h>


#define MAXSiIZE 100
#define TRUE    1
#define  FALSE   0

typedef struct{
    int data[MAXSiIZE];
    int last;
} SeqList;

SeqList SeqListInit();
SeqList SeqListInsert(SeqList L,int i, int x);
void ShowData(SeqList L);

SeqList SeqListDelete(SeqList L,int i);
SeqList SeqListMerge(SeqList Sla, SeqList Slb);


#endif /* MISeqList_h */
