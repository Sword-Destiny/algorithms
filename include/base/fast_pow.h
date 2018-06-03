//
// Created by yuanh on 2018/5/28.
//

#ifndef ALGORITHMS_FAST_POW_H

/**
 * 快速幂运算
 * @param x 底数
 * @param n 幂
 * @return 结果
 */
template<typename ll>
ll fast_pow(ll x, unsigned int n) {
    ll res = 1;
    while (n > 0) {
        if (n & (unsigned) 1) {
            res = res * x;
        }
        x = x * x;
        n >>= 1;
    }
    return res;
}

#define ALGORITHMS_FAST_POW_H

#endif //ALGORITHMS_FAST_POW_H
