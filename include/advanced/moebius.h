//
// Created by 袁浩 on 2018/10/25.
//

#ifndef ALGORITHMS_MOEBIUS_H

#include <vector>
#include <map>
#include <cmath>
#include "../base/mod.h"

using std::map;
using std::vector;

/**
 * 求n的所有的质因数的莫比乌斯函数值
 *
 * @param n
 * @return
 */
map<int, int> factor_moebius(int n) {
    map<int, int> res;
    vector<int> primes;

    // 枚举n的质因数
    int sn = (int) sqrt(n);
    for (int i = 2; i <= sn; ++i) {
        if (n % i == 0) {
            primes.push_back(i);
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n != 1) {
        primes.push_back(n);
    }

    int m = (int) primes.size();
    for (int i = 0; i < (1 << m); ++i) {
        int mu = 1, d = 1;
        for (int j = 0; j < m; ++j) {
            if (i >> j & 1) {
                mu *= -1;
                d *= primes[j];
            }
        }
        res[d] = mu;
    }
    return res;
}

/**
 * 求莫比乌斯函数值
 * 也就是所有由a~z（不一定使用所有字母）组成的长度为n的字符串中，没有周期性的字符串的个数
 *
 * @param n
 * @param MOD 由于这个数太大，所以返回取模的结果
 * @return
 */
int moebius(int n, int MOD) {
    int res = 0;
    map<int, int> mu = factor_moebius(n);
    for (auto &it : mu) {
        res += it.second * mod_pow(26, n / it.first, MOD);
        res = (res % MOD + MOD) % MOD;
    }
    return res;
}

#define ALGORITHMS_MOEBIUS_H

#endif //ALGORITHMS_MOEBIUS_H
