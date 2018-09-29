//
// Created by yuanhao on 18-9-29.
//

#ifndef ALGORITHMS_STOCK_CHARTS_H

#include "../mid_level/binary_partite_matching.h"

int stock_charts(int N, int K, int **p) {
    int v = N * 2;
    bool **can = new bool *[v];
    for (int i = 0; i < v; ++i) {
        can[i] = new bool[v];
        memset(can[i], 0, v * sizeof(bool));
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j)continue;
            bool f = true;
            for (int k = 0; k < K; ++k) {
                if (p[j][k] >= p[i][k]) {
                    f = false;
                }
            }
            if (f) {
                can[i][N + j] = true;
            }
        }
    }
    int ans = N - binary_partite_matching(v, v, can);
    for (int i = 0; i < v; ++i) {
        delete[] can[i];
    }
    delete[] can;
    return ans;
}

#define ALGORITHMS_STOCK_CHARTS_H

#endif //ALGORITHMS_STOCK_CHARTS_H
