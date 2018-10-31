//
// Created by yuanh on 2018/5/23.
//

#include "map_edge.h"

#ifndef ALGORITHMS_BELLMAN_FORD_H
#ifndef INF_INT
#define INF_INT 0x3fffffff
#endif

/**
 * 求最短路径算法,
 * bellman_ford算法虽然支持负边,但是注意不能存在负圈,
 * 否则某些点之间最短路径可能不存在.
 * @param G 图
 * @param d 保存结果距离
 * @param n 顶点数量
 * @param start_point 起始顶点
 * @param prev 前驱节点用于路径还原
 * @return 是否包含负圈,如果包含负圈,则某些点之间无最短路径
 */
bool bellman_ford_shortest_path(int **G, int *d, int n, int start_point, int *prev) {
    auto *es = new map_edge[n * n];
    int edge_num = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j] != INF_INT) {
                es[edge_num].from = i;
                es[edge_num].to = j;
                es[edge_num].weight = G[i][j];
                edge_num++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        d[i] = INF_INT;
        prev[i] = -1;
    }
    d[start_point] = 0;
    for (int v = 0; v < n; ++v) {
        bool update = false;
        for (int i = 0; i < edge_num; ++i) {
            map_edge e = es[i];
            if (d[e.from] != INF_INT && d[e.from] + e.weight < d[e.to]) {
                d[e.to] = d[e.from] + e.weight;
                prev[e.to] = e.from;
                update = true;
                if (v == n - 1) {
                    delete[] es;
                    return true;
                }
            }
        }
        if (!update) {
            break;
        }
    }
    delete[] es;
    return false;
}

#define ALGORITHMS_BELLMAN_FORD_H

#endif //ALGORITHMS_BELLMAN_FORD_H
