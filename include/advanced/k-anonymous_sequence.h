//
// Created by 天命剑主 on 2018-12-4.
//

#ifndef ALGORITHMS_K_ANONYMOUS_SEQUENCE_H
#define ALGORITHMS_K_ANONYMOUS_SEQUENCE_H

#include <deque>

using std::deque;

/**
 * 直线fj在x位置的值
 *
 * @param a 原输入数组
 * @param dp dp数组
 * @param s 预处理和
 */
long long f(int j, int x, const int *a, const long long *dp, const long long *s) {
    return -a[j] * x + dp[j] - s[j] + a[j] * j;
}

/**
 * 判断f2是否有可能成为最小值
 *
 * @param f1
 * @param f2
 * @param f3
 * @param a 原输入数组
 * @param dp dp数组
 * @param s 预处理和
 */
bool canBeSmallest(int f1, int f2, int f3, const int *a, const long long *dp, const long long *s) {
    long long a1 = -a[f1], b1 = dp[f1] - s[f1] + a[f1] * f1;
    long long a2 = -a[f2], b2 = dp[f2] - s[f2] + a[f2] * f2;
    long long a3 = -a[f3], b3 = dp[f3] - s[f3] + a[f3] * f3;
    return (a2 - a1) * (b3 - b2) >= (a3 - a2) * (b2 - b1);
}

/**
 * 给定一个长度为n的非严格单调递增序列a,
 * 每次一操作可以使数列中任意一项的值减小1,
 * 要使数列中每一项都满足数列中其他项有至少k-1项与它相等,
 * 求最少的操作次数.
 */
long long k_anonymous_sequence(int n, int k, const int *a) {
    auto *dp = new long long[n + 1];
    auto *s = new long long[n + 1];
    auto *deq = new int[n];

    s[0] = 0;
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + a[i];
    }

    int ds = 0, dt = 1;
    deq[0] = 0;
    dp[0] = 0;

    for (int i = k; i <= n; ++i) {
        if (i - k >= k) {
            while (ds + 1 < dt && canBeSmallest(deq[dt - 2], deq[dt - 1], i - k, a, dp, s)) {
                dt--;
            }
            deq[dt++] = i - k;
        }
        while (ds + 1 < dt && f(deq[ds], i, a, dp, s) >= f(deq[ds + 1], i, a, dp, s)) {
            ds++;
        }
        dp[i] = s[i] + f(deq[ds], i, a, dp, s);
    }

    long long ans = dp[n];

    delete[](dp);
    delete[](s);

    return ans;
}

#endif //ALGORITHMS_K_ANONYMOUS_SEQUENCE_H
