//
// Created by yuanhao on 2019-8-26.
//

#ifndef ALGORITHMS_MATRIX_MIN_DISTANCE_H
#define ALGORITHMS_MATRIX_MIN_DISTANCE_H

#include <iostream>
#include <cstring>

using namespace std;

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
