//
// Created by 袁浩 on 2018/10/26.
//

#ifndef ALGORITHMS_MOD_H

#include "gcd.h"

/**
 * 求a对m的逆元b, a≡b(mod m)
 *
 * @param a
 * @param m
 * @return
 */
int mod_inverse(int a, int m) {
    int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

/**
 * 求n的欧拉函数值,时间复杂度O(√n)
 * 即不大于n的自然数中与n互素的数的数量
 *
 * @param n
 * @return
 */
int euler_phi(int n) {
    int res = n;
    for (int i = 2; i * i < n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            for (; n % i == 0; n /= i);
        }
    }
    if (n != 1) {
        res = res / n * (n - 1);
    }
    return res;
}

/**
 * 用埃氏筛法在O(n)的时间内筛选出从0到n-1的欧拉函数值表
 *
 * @param n
 * @param euler
 */
void euler_phi2(int n, int *euler) {
    for (int i = 0; i < n; ++i) {
        euler[i] = i;
    }
    for (int i = 2; i < n; ++i) {
        if (euler[i] == i) {
            for (int j = i; j < n; j += i) {
                euler[j] = euler[j] / i * (i - 1);
            }
        }
    }
}

template<typename T>
/**
 * 取模的幂运算x的n次方
 *
 * @tparam T
 * @param x
 * @param n
 * @param mod
 * @return
 */
T mod_pow(T x, T n, T mod) {
    T res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

#define ALGORITHMS_MOD_H

#endif //ALGORITHMS_MOD_H
