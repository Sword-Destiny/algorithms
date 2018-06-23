//
// Created by yuanh on 2018/6/23.
//

#ifndef ALGORITHMS_THE_WINDYS_H

#include "min_cost_flow.h"
/**
 * POJ No.3686
 * 任务分配问题
 * @param n 任务数量
 * @param m 工厂数量
 * @param weights 每个任务在每个工厂完成需要的时间
 * @return 平均任务完成时间
 */
double the_windys(int n, int m, int **weights) {
    int s = n + n * m;
    int t = s + 1;
    int v = t + 1;
    auto *G = new vector<min_edge>[v];
    for (int i = 0; i < n; ++i) {
        add_edge(G, s, i, 1, 0);
    }
    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
            add_edge(G, n + j * n + k, t, 1, 0);
            for (int i = 0; i < n; ++i) {
                add_edge(G, i, n + j * n + k, 1, (k + 1) * weights[i][j]);
            }
        }
    }
    return (double) min_cost_flow(s, t, n, v, G) / n;
}

#define ALGORITHMS_THE_WINDYS_H

#endif //ALGORITHMS_THE_WINDYS_H
