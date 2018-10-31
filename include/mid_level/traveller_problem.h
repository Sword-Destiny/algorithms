//
// Created by yuanh on 2018/6/9.
//

#ifndef ALGORITHMS_TRAVELLER_PROBLEM_H
#ifndef INF_INT
#define INF_INT 0x3fffffff
#endif

#include <algorithm>

using std::fill;
using std::min;

template<typename T>
/**
 * 旅行商问题,状态压缩dp
 * @tparam T 类型参数
 * @param n 顶点数量
 * @param distance 距离
 * @return 最短路径
 */
T traveller_problem(int n, T **distance) {
    T **dp = new T *[1 << n];
    int N = (1 << n);
    for (int i = 0; i < N; ++i) {
        dp[i] = new T[n];
        fill(dp[i], dp[i] + n, INF_INT);
    }
    dp[N - 1][0] = 0;
    for (int s = N - 2; s >= 0; --s) {
        for (int v = 0; v < n; ++v) {
            for (int u = 0; u < n; ++u) {
                dp[s][v] = min(dp[s][v], dp[s | 1 << u][u] + distance[v][u]);
            }
        }
    }
    T res = dp[0][0];
    for (int i = 0; i < N; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
    return res;
}

#define ALGORITHMS_TRAVELLER_PROBLEM_H

#endif //ALGORITHMS_TRAVELLER_PROBLEM_H
