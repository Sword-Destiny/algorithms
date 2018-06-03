//
// Created by yuanh on 2018/5/25.
//

#ifndef ALGORITHMS_KRUSKAL_H
#ifndef INF_INT
#define INF_INT 0x3fffffff
#endif

#include "union_find_set.h"
#include "map_edge.h"
#include <algorithm>
using std::sort;

/**
 * kruskal最小生成树算法,prim算法类似于dijkstra,未实现
 * @param G 图
 * @param n 顶点数量
 * @param min_cost 最小树权值之和
 * @param res_edges 保存最小树,应该是n-1项
 */
void kruskal(int **G, int n, int &min_cost, map_edge *res_edges) {
    int edge_num = 0;
    auto *es = new map_edge[n * n];
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
    sort(es, es + edge_num);
    union_set uf(n);
    min_cost = 0;
    for (int i = 0; i < edge_num; ++i) {
        map_edge e = es[i];
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            min_cost += e.weight;
            es[i].weight = INF_INT;
        }
    }
    int index = 0;
    for (int i = 0; i < edge_num; ++i) {
        if (es[i].weight == INF_INT) {
            res_edges[index].from = es[i].from;
            res_edges[index].to = es[i].to;
            res_edges[index].weight = G[es[i].from][es[i].to];
            index++;
        }
    }
    delete[] es;
}

#define ALGORITHMS_KRUSKAL_H

#endif //ALGORITHMS_KRUSKAL_H
