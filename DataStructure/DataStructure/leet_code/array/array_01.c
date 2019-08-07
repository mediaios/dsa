//
//  array_01.c
//  DataStructure
//
//  Created by ethan on 2019/8/7.
//  Copyright © 2019 Maxwell. All rights reserved.
//

#include "array_01.h"

/*** 1064:不动点 ***/
int fixedPoint(int *A, int ASize)
{
    if (ASize < 1 || ASize >= 10*10*10*10) {
        return -1;
    }
    for (int i = 0; i < ASize; i++) {
        if (A[i] == i) {
            return i;
        }
    }
    return -1;
}

/*** 1085:最小元素各数位之和 ***/
int sumOfDigits(int* A, int ASize){
    if (ASize < 1 || ASize > 100) {
        return 1;
    }
    int min = A[0];
    for (int i = 1; i < ASize; i++) {
        if (A[i] < min ) {
            min = A[i];
        }
    }
    
    printf("min: %d\n",min);
    int s = 0;
    while (min/10) {
        int y = min%10;
        min = min/10;
        s += y;
    }
    s+=min;
    return s%2 == 0 ? 1 : 0;
}


void swap_sort(int array[],int a,int b)
{
    array[a] ^= array[b];
    array[b] ^= array[a];
    array[a] ^= array[b];
}

/*** 977:有序数组的平方 ***/
int* sortedSquares(int* A, int ASize, int* returnSize){
    int *B = (int *)malloc(sizeof(int) * ASize);
    for (int i = 0; i < ASize; i++) {
        B[i] = A[i] * A[i];
    }
    
    // buble sort
    int exchange = 1;
    for (int i = 1 && exchange; i < ASize; i++) {
        exchange  = 0;
        for (int j = 0 ; j < ASize-i; j++) {
            if (B[j] > B[j+1]) {
                swap_sort(B,j,j+1);
                exchange = 1;
            }
        }
    }
    *returnSize = ASize;
    return B;
}
