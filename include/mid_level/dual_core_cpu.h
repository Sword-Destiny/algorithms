//
// Created by yuanh on 2018/6/21.
//

#ifndef ALGORITHMS_DUAL_CORE_CPU_H

#include "dinic.h"

#define CPU_A 0
#define CPU_B 1
#define trans_a 0
#define trans_b 1
#define trans_w 2

/**
 * POJ No.3469
 * @param n 模块数
 * @param m 需要数据交换的模块数
 * @param weights 模块在两个核上分别的花费
 * @param trans 模块之间需要交换数据的花费
 * @return 最小花费
 */
int dual_core_cpu(int n, int m, int **weights, int **trans) {
    int s = n;
    int t = s + 1;
    int v = t + 1;
    auto *G = new vector<di_edge>[v];

    for (int i = 0; i < n; ++i) {
        add_edge(G, i, t, weights[i][CPU_A]);
        add_edge(G, s, i, weights[i][CPU_B]);
    }

    for (int i = 0; i < m; ++i) {
        add_edge(G, trans[i][trans_a], trans[i][trans_b], trans[i][trans_w]);
        add_edge(G, trans[i][trans_b], trans[i][trans_a], trans[i][trans_w]);
    }

    return dinic_max_flow(s, t, G, v);
}


#define ALGORITHMS_DUAL_CORE_CPU_H

#endif //ALGORITHMS_DUAL_CORE_CPU_H
