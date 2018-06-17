//
// Created by yuanh on 2018/6/12.
//

#ifndef ALGORITHMS_BINARY_GRAPH_FLOW_H

#include "dinic.h"

/**
 * 二分图分配问题
 * @param C 计算机数量
 * @param T 任务数量
 * @param can 某台计算机是否能完成某个任务
 * @return 能完成的最大任务数量
 */
int binary_partite_matching(int C, int T, bool **can) {
    int s = C + T;
    int t = s + 1;
    int v = t + 1;
    auto *G = new vector<di_edge>[v];
    for (int i = 0; i < C; ++i) {
        add_edge(G, s, i, 1);
    }
    for (int i = 0; i < T; ++i) {
        add_edge(G, C + i, t, 1);
    }
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < T; ++j) {
            if (can[i][j]) {
                add_edge(G, i, C + j, 1);
            }
        }
    }
    int flow = dinic_max_flow(s, t, G, v);
    delete[] G;
    return flow;
}


#define ALGORITHMS_BINARY_GRAPH_FLOW_H

#endif //ALGORITHMS_BINARY_GRAPH_FLOW_H
