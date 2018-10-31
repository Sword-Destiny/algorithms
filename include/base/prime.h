//
// Created by yuanh on 2018/5/26.
//

#ifndef ALGORITHMS_PRIME_H

#include <cmath>
#include <vector>
#include <map>

using std::map;
using std::sqrt;
using std::vector;
using std::round;

template <typename T>
/**
 * 判断一个数是否是素数
 * @tparam T
 * @param n
 * @return
 */
bool is_prime(T n) {
    auto sn = (T) round(sqrt(n));
    for (T i = 2; i <= sn; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return n != 1;
}

template <typename T>
/**
 * 求约数
 * @param n 数
 * @return 约数
 */
vector<T> divisor(T n) {
    auto sn = (T) round(sqrt(n));
    vector<T> res;
    for (T i = 1; i <= sn; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) {
                res.emplace_back(n / i);
            }
        }
    }
    return res;
}

template <typename T>
/**
 * 因式分解
 * @param n 数
 * @return 因式分解
 */
map<T, T> prime_factor(T n) {
    map<T, T> res;
    auto sn = (T) round(sqrt(n));
    for (T i = 2; i <= sn; ++i) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) {
        res[n] = 1;
    }
    return res;
};

#define ALGORITHMS_PRIME_H

#endif //ALGORITHMS_PRIME_H
