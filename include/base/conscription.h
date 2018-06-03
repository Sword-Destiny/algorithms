//
// Created by yuanh on 2018/5/26.
//
#ifndef ALGORITHMS_CONSCRIPTION_H

#include "kruskal.h"

#define COST 10000 //招募每个人的费用

/**
 * POJ 3723
 * 招兵
 * @param n 女兵数量
 * @param m 男兵数量
 * @param r 关系数量
 * @param relations 亲密关系
 * @return 招募所需最小cost
 */
int conscription(int n,int m,int r,int*relations[3]) {
    int v = m + n;
    auto **G = new int *[v];
    for (int i = 0; i < v; ++i) {
        G[i] = new int[v];
        for (int j = 0; j < v; ++j) {
            G[i][j] = COST;
        }
    }
    for (int i = 0; i < r; ++i) {
        G[relations[i][0]][relations[i][1] + n] = COST - relations[i][2];
    }
    int min_cost = 0;
    auto *es = new map_edge[v - 1];
    kruskal(G, v, min_cost, es);
    for (int i = 0; i < v; ++i) {
        delete[] G[i];
    }
    delete[] G;
    delete[] es;
    return min_cost + COST;
}

#define ALGORITHMS_CONSCRIPTION_H

#endif //ALGORITHMS_CONSCRIPTION_H
