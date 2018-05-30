//
// Created by yuanh on 2018/5/30.
//

#ifndef ALGORITHMS_AGGRESSIVE_COWS_H

#include <algorithm>

using std::sort;

bool fit(int d, int N, int M, const int *ns) {
    int last = 0;
    for (int i = 1; i < M; ++i) {
        int current = last + 1;
        while (ns[current] - ns[last] < d && current < N) {
            current++;
        }
        if (current == N) {
            return false;
        }
        last = current;
    }
    return true;
}

/**
 * POJ No.2456
 * 安排牛舍
 * 求最大的最小距离
 * @param N 牛舍的数量
 * @param M 牛的数量
 * @param ns 牛舍的位置
 * @param res 最终的安排结果
 * @return 最终安排牛舍之间最小的距离
 */
int aggressive_cows(int N, int M, int *ns, int *res) {
    sort(ns, ns + N);
    int lb = 0;
    int ub = 0;
    for (int i = 1; i < N; ++i) {
        int d = ns[i] - ns[i - 1] + 1;
        if (d > ub) {
            ub = d;
        }
    }
    while (ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if (fit(mid, N, M, ns)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    int index = 0;
    int last = 0;
    res[index++] = ns[last];
    for (int i = 1; i < M; ++i) {
        int current = last + 1;
        while (ns[current] - ns[last] < lb) {
            current++;
        }
        last = current;
        res[index++] = ns[last];
    }
    return lb;
}

#define ALGORITHMS_AGGRESSIVE_COWS_H

#endif //ALGORITHMS_AGGRESSIVE_COWS_H
