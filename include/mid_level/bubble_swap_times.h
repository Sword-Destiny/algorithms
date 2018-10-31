//
// Created by yuanh on 2018/6/5.
//

#ifndef ALGORITHMS_BUBBLE_SWAP_TIME_H

#include "binary_indexed_tree.h"

/**
 * 冒泡排序交换的次数
 * @param n 数组长度
 * @param arr 数组
 * @return 次数
 */
long long bubble_swap_times(int n,int *arr){
    bi_tree<int> bt = binary_indexed_tree<int>(n,n);
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        answer +=i - bt.sum(arr[i]);
        bt.add(arr[i],1);
    }
    return answer;
}

#define ALGORITHMS_BUBBLE_SWAP_TIME_H

#endif //ALGORITHMS_BUBBLE_SWAP_TIME_H
