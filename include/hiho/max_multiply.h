//
// Created by yuanhao on 2019-8-16.
//

#ifndef ALGORITHMS_MAX_MULTIPLY_H
#define ALGORITHMS_MAX_MULTIPLY_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 描述
 * 给定N个数A1, A2, A3, ... AN，小Ho想从中找到两个数Ai和Aj(i ≠ j)使得乘积Ai × Aj × (Ai AND Aj)最大。其中AND是按位与操作。
 * 小Ho当然知道怎么做。现在他想把这个问题交给你。
 * 输入
 * 第一行一个数T，表示数据组数。(1 <= T <= 10)
 * 对于每一组数据：
 * 第一行一个整数N（1<=N<=100,000）
 * 第二行N个整数A1, A2, A3, ... AN (0 <= Ai <220)
 * 输出
 * 一个数表示答案
 * 样例输入
 * 2
 * 3
 * 1 2 3
 * 4
 * 1 2 4 5
 * 样例输出
 * 12
 * 80
 * @param numbers
 * @return
 */
long long max_multiply(vector<long long> &large_numbers) {
    sort(large_numbers.begin(), large_numbers.end());
    // TODO 现在这个算法会超时
    long long max_logic_and = 0;
    for (int i = 0; i < large_numbers.size() - 1; ++i) {
        int j = i + 1;
        long long ans = large_numbers[i] * large_numbers[j] * (large_numbers[i] & large_numbers[j]);
        if (ans > max_logic_and) {
            max_logic_and = ans;
        }
    }
    return max_logic_and;
}

#endif //ALGORITHMS_MAX_MULTIPLY_H
