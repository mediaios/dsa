//
//  main.c
//  DataStructure
//
//  Created by mediaios on 2019/7/18.
//  Copyright © 2019 mediaios. All rights reserved.
//

#include <stdio.h>
#include "MISort.h"
#include "MISearch.h"
#include "MIStack.h"
#include "MIQueue.h"
#include "MISeqList.h"


void swap2(int array[],int a,int b)
{
    array[a] ^= array[b];
    array[b] ^= array[a];
    array[a] ^= array[b];
}

void printArray2(int array[],int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d\t",array[i]);
    }
    printf("\n");
}


void bubleSort2(int array[],int size)
{
    int exchange  = 1;
    for (int i = 1; i < size && exchange; i++) {
        exchange = 0;
        for (int j = 0; j < size-i; j++) {
            if (array[j] > array[j+1]) {
                swap2(array, j, j+1);
                exchange = 1;
            }
        }
    }
    
    printArray2(array, size);
}

void insertSort2(int array[],int size)
{
    for (int i = 1; i < size; i++) {
        int temp = array[i],j;
        for (j = i-1; j >=0 && temp < array[j]; j--)
            array[j+1] = array[j];
        array[j+1]  = temp;
    }
    printArray2(array, size);
}

void shellSort2(int array[],int size)
{
    for (int delta  = size/2; delta >=1; delta /= 2) {  // 首先要分组
        for (int i = 0; i < size; i++) {
            int temp = array[i],j;
            for (j = i-delta; j >=0 && temp < array[j]; j -= delta)
                array[j+delta] = array[j];
            array[j+delta] = temp;
        }
    }
    printArray2(array, size);
}

void selectSort2(int array[],int size)
{
    
    for (int i = 0;  i < size; i++) {
        int minIndex  = i;
        for (int j = i ; j < size; j++) {
            if (array[j] < array[i]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swap2(array, i, minIndex);
        }
    }
    printArray2(array, size);
}


void quickSortImp2(int array[],int begin,int end)
{
    if (begin < end) {
        int i = begin,j=end;
        int vot =array[i];
        while (i != j) {
            
            while (i < j && vot < array[j])
                j--;
            if (i < j)   // 小元素向前移动
                array[i++] = array[j];
            while (i < j && vot > array[i])
                i++;
            if (i < j)
                array[j--] = array[i];
        }
        array[i] = vot;
        quickSortImp2(array, begin, j-1);
        quickSortImp2(array, i+1, end);
    }
}

void quickSort2(int array[],int size)
{
    quickSortImp2(array, 0, size-1);
    printArray2(array, size);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*** 测试栈 ***/
//    test();
    
    /*** 测试队列 ***/
    testQueue();
    
    
    
    
    
//    int array[] = {2,45,3,67,10,4,109,0,-1,11};
//    bubleSort2(array, 10);
//    insertSort2(array, 10);
//    shellSort2(array, 10);
//    quickSort2(array, 10);
    
    
//    bubleSort(array, 10);
//    bubleSortQuick(array, 10);
//    inserSort(array, 10);
//    shellSort(array, 10);
//    selectSort(array, 10);
//    quickSort(array, 10);
    
//
//    // 查找
//    int sArray[] = {1,2,3,4,5,6,7,8,9,10};
//    int index = binarySearch(sArray, 10, 5);
//    printf("5在序列中的位置为:%d \n",index);
//    return 0;
    
//    SeqList sqList = SeqListInit();
//    SeqListInsert(sqList, 1, 10);
//    SeqListInsert(sqList, 2, 10);
//    SeqListInsert(sqList, 3, 10);
//    SeqList newSqL = SeqListInsert(sqList, 4, 10);
////    SeqListInsert(sqList, 1, 20);
//    ShowData(newSqL);
    
    return 0;
}
