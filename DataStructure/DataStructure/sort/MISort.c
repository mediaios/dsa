//
//  MISort.c
//  DataStructure
//
//  Created by mediaios on 2019/7/20.
//  Copyright © 2019 mediaios. All rights reserved.
//

#include "MISort.h"



void swap(int array[],int a,int b)
{
    array[a] ^= array[b];
    array[b] ^= array[a];
    array[a] ^= array[b];
}

void printArray(int array[],int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d\t",array[i]);
    }
    printf("\n");
}

void bubleSort(int array[], int size)
{
    for (int i = 1; i < size; i++) {  // 首先进行n-1趟扫描
        for (int j = 0; j < size - i; j++) {
            if (array[j] > array[j+1]) {
                swap(array, j, j+1);
            }
        }
    }
    printArray(array, size);
}


/**
 优化后的冒泡排序
 
 @param array 待排序的数组
 @param size 数组的长度
 */
void bubleSortQuick(int array[], int size)
{
    int exchange = 1;
    for (int i = 1; i < size  && exchange; i++) {
        exchange = 0;
        for (int j = 0; j < size -i; j++) {
            if (array[j] > array[j+1]) {
                swap(array, j, j+1);
                exchange = 1;
            }
        }
    }
    printArray(array, size);
}


void inserSort(int array[],int size)
{
    for (int i = 1; i < size; i++) {  // n-1趟扫描
        int temp = array[i],j;  // 每趟将array[i]插入到前面排好的序列中去
        for (j = i-1; j >= 0 && temp < array[j]; j--) {
            array[j+1] = array[j];
        }
        array[j+1] = temp;
    }
    printArray(array, size);
}


void shellSort(int array[],int size)
{
    for (int delta =size/2; delta > 0; delta /= 2) {
        for (int i = delta; i < size; i++) {
            int temp = array[i],j;
            for (j = i-delta; j >= 0 && temp < array[j]; j -= delta) {
                array[j+delta] = array[j];
            }
            array[j+delta] = temp;
        }
    }
    printArray(array, size);
}


void selectSort(int array[],int size)
{
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        
        if (min != i) {
            swap(array, min, i);
        }
    }
    
    printArray(array, size);
}


void quickSortImp(int array[],int begin,int end)
{
    if (begin < end) {
        int i = begin,j = end;
        int vot  = array[i];
        while (i != j) {  // i==j时，本次排序完成
            while (i < j && vot < array[j])  // 移动基准值后面的游标
                j--;
            if (i < j)  // 当基准值有侧有小元素时
                array[i++] = array[j];   // 将小元素放到基准值前面
            while (i < j && vot > array[i])  // 移动基准值前面的游标
                i++;
            if (i < j)   // 此时基准值前面有大元素
                array[j--] = array[i];  // 将大元素放到基准值右侧
        }
        array[i] = vot;
        quickSortImp(array, begin, j-1);
        quickSortImp(array, i+1, end);
    }
}


void quickSort(int array[],int size)
{
    quickSortImp(array, 0, size-1);
    printArray(array, size);
}
