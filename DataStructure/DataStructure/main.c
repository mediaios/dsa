//
//  main.c
//  DataStructure
//
//  Created by mediaios on 2019/7/18.
//  Copyright © 2019 mediaios. All rights reserved.
//

#include <stdio.h>
#include "MISeqList.h"
#include "MISort.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int array[] = {2,45,3,67,10,4,109,0,-1,11};
//    bubleSort(array, 10);
//    bubleSortQuick(array, 10);
//    inserSort(array, 10);
//    shellSort(array, 10);
//    selectSort(array, 10);
    quickSort(array, 10);
    return 0;
    
    SeqList sqList = SeqListInit();
    SeqListInsert(sqList, 1, 10);
    SeqListInsert(sqList, 2, 10);
    SeqListInsert(sqList, 3, 10);
    SeqList newSqL = SeqListInsert(sqList, 4, 10);
//    SeqListInsert(sqList, 1, 20);
    ShowData(newSqL);
    
    return 0;
}
