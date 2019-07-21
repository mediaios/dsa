//
//  MISearch.h
//  DataStructure
//
//  Created by mediaios on 2019/7/21.
//  Copyright © 2019 mediaios. All rights reserved.
//

#ifndef MISearch_h
#define MISearch_h

#include <stdio.h>


/**
 二分查找

 @param array 待查找的数据序列
 @param size s序列长度
 @param ele 待查找的元素
 @return 返回待查找元素在数据序列中的索引，如果找不到,默认返回-1
 */
int binarySearch(int array[],int size,int ele);

#endif /* MISearch_h */
