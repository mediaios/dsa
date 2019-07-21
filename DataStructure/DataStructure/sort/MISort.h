//
//  MISort.h
//  DataStructure
//
//  Created by mediaios on 2019/7/20.
//  Copyright © 2019 mediaios. All rights reserved.
//

#ifndef MISort_h
#define MISort_h

#include <stdio.h>



/**
 冒泡排序

 @param array 待排序的数组
 @param size 数组的长度
 */
void bubleSort(int array[], int size);


/**
 优化后的冒泡排序

 @param array 待排序的数组
 @param size 数组的长度
 */
void bubleSortQuick(int array[], int size);



/**
 直接插入排序

 @param array 待排序的数组
 @param size 数组的长度
 */
void inserSort(int array[],int size);



/**
 希尔排序

 @param array 待排序的数组
 @param size 数组长度
 */
void shellSort(int array[],int size);



/**
 直接选择排序

 @param array 待排序的数组
 @param size 数组长度
 */
void selectSort(int array[],int size);



/**
 快速排序

 @param array 待排序的数组
 @param size 数组长度
 */
void quickSort(int array[],int size);

#endif /* MISort_h */
