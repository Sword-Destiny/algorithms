//
// Created by yuanh on 2018/5/29.
//

#ifndef ALGORITHMS_CABLE_MASTER_H

#include <cmath>

using std::floor;

bool fit(int N, int K, const double *L, double mid) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += (int) (L[i] / mid);
    }
    return sum >= K;
}

/**
 * POJ No.1064
 * 分绳子
 * @param N 绳子数量
 * @param K 要分割的绳子数量
 * @param L 绳子的长度
 * @param accuracy 精度
 * @return 分得的绳子的最长长度
 */
double cable_master(int N, int K, const double *L, double accuracy) {
    double INF = L[0];
    for (int i = 1; i < N; ++i) {
        if (L[i] > INF) {
            INF = L[i];
        }
    }
    double lb = 0; //下界
    double ub = INF; //上界
    while (ub - lb > accuracy) {
        double mid = (ub + lb) / 2;
        if (fit(N, K, L, mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    return lb;
}

#define ALGORITHMS_CABLE_MASTER_H

#endif //ALGORITHMS_CABLE_MASTER_H
