//
// Created by yuanh on 2018/6/18.
//

#ifndef ALGORITHMS_DINING_H

#include "dinic.h"

/**
 * POJ No.3281
 * 给每头牛喜欢的食物和饮料
 * 转化为最大流求解
 * @param N 牛的总数
 * @param F 食物种类
 * @param D 饮料的种类
 * @param like_foods 牛喜欢的食物
 * @param like_drinks 牛喜欢的饮料
 * @return 能满足的牛的数量
 */
int dining(int N, int F, int D, bool **like_foods, bool **like_drinks) {
    int s = N * 2 + F + D;
    int t = s + 1;
    int v = t + 1;
    vector<di_edge> *G = new vector<di_edge>[v];
    for (int i = 0; i < F; ++i) {
        add_edge(G, s, N * 2 + i, 1);
    }
    for (int i = 0; i < D; ++i) {
        add_edge(G, N * 2 + F + i, t, 1);
    }
    for (int i = 0; i < N; ++i) {
        add_edge(G, i, N + i, 1);
        for (int j = 0; j < F; ++j) {
            if (like_foods[i][j]) {
                add_edge(G, N * 2 + j, i, 1);
            }
        }
        for (int j = 0; j < D; ++j) {
            if (like_drinks[i][j]) {
                add_edge(G, N + i, N * 2 + F + j, 1);
            }
        }
    }
    return dinic_max_flow(s, t, G, v);
}


#define ALGORITHMS_DINING_H

#endif //ALGORITHMS_DINING_H
