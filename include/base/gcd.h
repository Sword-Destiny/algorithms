//
// Created by yuanh on 2018/5/26.
//

#ifndef ALGORITHMS_GCD_H

template<typename T>
/**
 *
 * 求a和b的最大公约数
 *
 * @tparam T
 * @param a
 * @param b
 * @return
 */
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

template<typename T>
/**
 * 扩展gcd算法
 * ax+by=1,已知a和b,求x和y
 *
 * @tparam T
 * @param a
 * @param b
 * @param x
 * @param y
 * @return
 */
T extgcd(T a, T b, T &x, T &y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

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

#define ALGORITHMS_GCD_H

#endif //ALGORITHMS_GCD_H
