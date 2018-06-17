//
// Created by yuanh on 2018/6/17.
//

#ifndef ALGORITHMS_ASTEROIDS_H

#include "../../include/mid_level/binary_partite_matching.h"

/**
 * POJ No.3041
 * 摧毁小行星问题
 * 是最小顶点覆盖问题
 * 在二分图转化为最大匹配问题
 * 于是可以用最大流算法解决
 * @param row 行
 * @param column 列
 * @param m 小行星位置
 * @return 摧毁小行星需要的最少光束
 */
int asteroids(int row, int column, bool **m) {
    return binary_partite_matching(row, column, m);
}

#define ALGORITHMS_ASTEROIDS_H

#endif //ALGORITHMS_ASTEROIDS_H
