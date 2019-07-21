//
//  MISearch.c
//  DataStructure
//
//  Created by ethan on 2019/7/21.
//  Copyright © 2019 Maxwell. All rights reserved.
//

#include "MISearch.h"


int binarySearch(int array[],int size,int ele)
{
    int begin = 0, end = size -1,mid;
    while (begin < end) {
        mid = (end - begin)/2;
        if (array[mid] > ele){
            end  = mid -1;
        }else if(array[mid] < ele){
            begin = mid +1;
        }else {
            return mid;
        }
    }
    return -1;
}
