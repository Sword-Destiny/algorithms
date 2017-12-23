//
// Created by sworddestiny on 17-12-18.
//

#ifndef ALGORITHMS_LONGEST_INCREASING_SUBSEQUENCE_H
#define ALGORITHMS_LONGEST_INCREASING_SUBSEQUENCE_H

#include <algorithm>

using std::max;
using std::fill;
using std::lower_bound;

/**
 * 最长递增子序列
 * @param a 序列
 * @param n 序列长度
 * @return 最长递增子序列长度
 */
int longest_increasing_subsequence(const int *a, int n) {
    auto *dp = new int[n];
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    delete[] dp;
    return res;
}

#define INF_INT 0x7fffffff

/**
 * 最长递增子序列(复杂度nlog(n))
 * @param a 序列
 * @param n 序列长度
 * @return 最长递增子序列长度
 */
int longest_increasing_subsequence_efficient(const int *a, int n) {
    auto *dp = new int[n];
    fill(dp, dp + n, INF_INT);
    for (int i = 0; i < n; i++) {
        *lower_bound(dp, dp + n, a[i]) = a[i];
    }
    int result = static_cast<int>(lower_bound(dp, dp + n, INF_INT) - dp);
    delete[] dp;
    return result;
}

#endif //ALGORITHMS_LONGEST_INCREASING_SUBSEQUENCE_H
