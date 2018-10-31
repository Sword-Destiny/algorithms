//
// Created by yuanh on 2018/6/7.
//

#ifndef ALGORITHMS_BLOCKS_H

#include "matrix.h"

template<typename T>
/**
 * 染色问题,使用递推矩阵求解
 * POJ No.3734
 * @tparam T 类型参数
 * @param n n
 * @param mod 模
 * @return 方案个数
 */
T blocks(unsigned int n, T mod) {
    matrix<T> m(3, 3);
    m[0][0] = 2;
    m[0][1] = 1;
    m[0][2] = 0;
    m[1][0] = 2;
    m[1][1] = 2;
    m[1][2] = 2;
    m[2][0] = 0;
    m[2][1] = 1;
    m[2][2] = 2;
    m = m.pow(n, mod);
    return m[0][0];
}

#define ALGORITHMS_BLOCKS_H

#endif //ALGORITHMS_BLOCKS_H
