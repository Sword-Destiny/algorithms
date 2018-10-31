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

#define ALGORITHMS_GCD_H

#endif //ALGORITHMS_GCD_H
