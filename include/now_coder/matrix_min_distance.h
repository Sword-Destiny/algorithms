//
// Created by yuanhao on 2019-8-26.
//

#ifndef ALGORITHMS_MATRIX_MIN_DISTANCE_H
#define ALGORITHMS_MATRIX_MIN_DISTANCE_H

#include <iostream>
#include <cstring>

using namespace std;
/**
 * 给定一个 n * m 的矩阵 a，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，路径上所有的数字累加起来就是路径和，输出所有的路径中最小的路径和。
 *
 * 输入描述:
 * 第一行输入两个整数 n 和 m，表示矩阵的大小。
 *
 * 接下来 n 行每行 m 个整数表示矩阵。
 *
 *
 * 输出描述:
 * 输出一个整数表示答案。
 * 示例1
 * 输入
 * 4 4
 * 1 3 5 9
 * 8 1 3 4
 * 5 0 6 1
 * 8 8 4 0
 * 输出
 * 1
 */
/**
 * The truth that you leave
 * The path that I go through
 * Both are the nearest
 */
int matrix_min_distance(int n, int m, int **matrix) {
    int res = 0;
    int **dp = new int *[n];
    for (int i = 0; i < n; ++i) {
        dp[i] = new int[m];
        memset(dp[i], 0, m * sizeof(int));
    }
    dp[0][0] = matrix[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0 && j > 0) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
            } else if (i > 0 && j == 0) {
                dp[i][j] = dp[i - 1][j] + matrix[i][j];
            } else if (i == 0 && j > 0) {
                dp[i][j] = dp[i][j - 1] + matrix[i][j];
            } else {
                dp[i][j] = matrix[i][j];
            }
        }
    }
    res = dp[n - 1][m - 1];
    for (int i = 0; i < n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
    return res;
}

#endif //ALGORITHMS_MATRIX_MIN_DISTANCE_H
