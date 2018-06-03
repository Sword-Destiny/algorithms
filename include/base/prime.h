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

bool is_prime(int n) {
    int sn = (int) sqrt(n);
    for (int i = 0; i <= sn; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return n != 1;
}

/**
 * 求约数
 * @param n 数
 * @return 约数
 */
vector<int> divisor(int n) {
    int sn = (int) sqrt(n);
    vector<int> res;
    for (int i = 1; i < sn; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) {
                res.emplace_back(n / i);
            }
        }
    }
    return res;
}

/**
 * 因式分解
 * @param n 数
 * @return 因式分解
 */
map<int, int> prime_factor(int n) {
    map<int, int> res;
    int sn = (int) sqrt(n);
    for (int i = 2; i <= sn; ++i) {
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
