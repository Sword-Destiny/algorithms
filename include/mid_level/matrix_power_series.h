//
// Created by yuanh on 2018/6/8.
//

#ifndef ALGORITHMS_MATRIX_POWER_SERIES_H

#include "matrix.h"

template<typename T>
/**
 * POJ No.3233
 * 求矩阵的前k次幂和
 * 注意矩阵m的行列必须相等
 * @tparam T 类型参数
 * @param m 矩阵
 * @param k 最高k次幂
 * @param mod 数字太大求模
 * @return 结果
 */
matrix<T> matrix_power_series(matrix<T> m, int k, T mod) {
    matrix<T> b(m.row * m.row, m.column * m.column);
    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.column; ++j) {
            b[i][j] = m[i][j];
        }
        b[m.row + i][i] = b[m.row + i][m.column + i] = 1;
    }
    b = b.pow(k + 1);
    matrix<T> res(m.row, m.column);
    for (int i = 0; i < m.row; ++i) {
        for (int j = 0; j < m.column; ++j) {
            T a = b[m.row + i][j] % mod;
            if (i == j) {
                a = (a + mod - 1) % mod;
            }
            res[i][j] = a;
        }
    }
    return res;
}

#define ALGORITHMS_MATRIX_POWER_SERIES_H

#endif //ALGORITHMS_MATRIX_POWER_SERIES_H
