//
// Created by 袁浩 on 2018/10/26.
//

#ifndef ALGORITHMS_COLOR_STONE_H

#include <map>
#include "../base/prime.h"
#include "../base/mod.h"

using std::map;

template<typename T>
/**
 * 对数量为n的一圈石头,用m种颜色染色,求一共有多少种方案(旋转相同的视为同一种方案),结果对mod取模
 *
 * @tparam T
 * @param n
 * @param m
 * @param mod
 * @return
 */
T color_stone(T n, T m, T mod) {
    map<T, T> primes = prime_factor(n);
    vector<T> divs = divisor(n);
    T res = 0;
    for (auto i = 0; i < divs.size(); ++i) {
        T euler = divs[i];
        for (auto prime:primes) {
            if (divs[i] % prime.first == 0) {
                euler = euler / prime.first * (prime.first - 1);
            }
        }
        res += euler * mod_pow(m, n / divs[i], mod) % mod;
        res %= mod;
    }
    return res * mod_pow(n, mod - 2, mod) % mod;
}

#define ALGORITHMS_COLOR_STONE_H

#endif //ALGORITHMS_COLOR_STONE_H
