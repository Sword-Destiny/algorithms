//
// Created by 天命剑主 on 2018-11-30.
//

#ifndef ALGORITHMS_SLICE_MIN_H
#define ALGORITHMS_SLICE_MIN_H

#include <deque>

using std::deque;

/**
 * 在n个数a1到an中选择k个数，求其中最小的和，其实也就是求a中最小的k个数
 * 结果索引放在res_index中
 * @return 最小和
 */
int slice_min(unsigned long n, const int *a, int k, int *res_index) {
    int *b = new int[n];
    deque<int> deq(n);

    for (int i = 0; i < n; ++i) {
        while (!deq.empty() && a[deq.back()] >= a[i]) {
            deq.pop_back();
        }
        deq.push_back(i);
        if (i - k + 1 >= 0) {
            b[i - k + 1] = deq.front();
            if (deq.front() == i - k + 1) {
                deq.pop_front();
            }
        }
    }
    int res = 0;
    for (int i = 0; i < k; ++i) {
        res_index[i] = b[i];
        res += a[b[i]];
    }

    delete[](b);
    return res;
}

#endif //ALGORITHMS_SLICE_MIN_H
