//
// Created by yuanh on 2018/6/22.
//

#ifndef ALGORITHMS_FARM_TOUR_H
#define param_a 0
#define param_b 1
#define param_c 2

#include "min_cost_flow.h"

/**
 * POJ No.2135
 * @param n 顶点数量
 * @param m 道路数量
 * @param params 道路参数
 * @return 参观路线总长度最小值
 */
int farm_tour(int n, int m, int **params) {
    int s = 0;
    int t = n - 1;
    int v = n;
    auto *G = new vector<min_edge>[v];
    for (int i = 0; i < m; ++i) {
        add_edge(G, params[i][param_a], params[i][param_b], 1, params[i][param_c]);
        add_edge(G, params[i][param_b], params[i][param_a], 1, params[i][param_c]);
    }

    return min_cost_flow(s, t, 2, v, G);
}

#define ALGORITHMS_FARM_TOUR_H

#endif //ALGORITHMS_FARM_TOUR_H
