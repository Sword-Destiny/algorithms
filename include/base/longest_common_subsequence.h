//
// Created by sworddestiny on 17-12-16.
//

#ifndef ALGORITHMS_LONGEST_COMMON_SUBSEQUENCE_H
#define ALGORITHMS_LONGEST_COMMON_SUBSEQUENCE_H

#include <algorithm>
#include <cstring>

using std::max;
using std::memset;

/**
 * 最长公共子序列
 * @param s 序列1
 * @param sn 序列1长度
 * @param t 序列2
 * @param tm 序列2长度
 * @return 最长公共子序列长度
 */
int longest_common_subsequence(const char *s, int sn, const char *t, int tm) {
    auto **dp = new int *[sn + 1];
    for (int i = 0; i <= sn; i++) {
        dp[i] = new int[tm + 1];
        memset(dp[i], 0, sizeof(int) * (tm + 1));
    }
    for (int i = 0; i < sn; i++) {
        for (int j = 0; j < tm; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    int result = dp[sn][tm];
    for (int i = 0; i <= sn; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return result;
}

#endif //ALGORITHMS_LONGEST_COMMON_SUBSEQUENCE_H
