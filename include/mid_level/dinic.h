//
// Created by yuanh on 2018/6/11.
//

#ifndef ALGORITHMS_DINIC_H

#ifndef INF_INT
#define INF_INT 0x3fffffff
#endif

#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using std::min;
using std::vector;
using std::queue;
using std::memset;

typedef struct _dinic_edge {
    int to;//终点
    int capacity;//容量
    int reverse;//反向边
} di_edge;


void add_edge(vector<di_edge> *G, int from, int to, int capacity) {
    G[from].emplace_back((di_edge) {to, capacity, (int) G[to].size()});
    G[to].emplace_back((di_edge) {from, 0, (int) G[from].size() - 1});
}

/**
 * bfs计算源点出发的距离
 * @param s 源点
 * @param V 顶点数量
 * @param G 图
 * @param level 顶点到源点的距离
 */
void bfs(int s, int V, vector<di_edge> *G, int *level) {
    memset(level, -1, sizeof(*level) * V);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            di_edge &e = G[v][i];
            if (e.capacity > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

/**
 * dfs寻找增广路
 * @param s 源点
 * @param t 目的点
 * @param flow 流
 * @param V 顶点数量
 * @param G 图
 * @param level 顶点到源点的距离
 * @param iter 当前弧,在其之前的边已经没用了
 * @return
 */
int dfs(int s, int t, int flow, int V, vector<di_edge> *G, int *level, int *iter) {
    if (s == t) {
        return flow;
    }
    for (int &i = iter[s]; i < G[s].size(); ++i) {
        di_edge &e = G[s][i];
        if (e.capacity > 0 && level[s] < level[e.to]) {
            int d = dfs(e.to, t, min(flow, e.capacity), V, G, level, iter);
            if (d > 0) {
                e.capacity -= d;
                G[e.to][e.reverse].capacity += d;
                return d;
            }
        }
    }
    return 0;
}

/**
 * dinic 最大流算法
 * @param s 源点
 * @param t 目的点
 * @param G 图
 * @param V 顶点数量
 * @return 最大流
 */
int dinic_max_flow(int s, int t, vector<di_edge> *G, int V) {
    int flow = 0;
    auto *level = new int[V];
    auto *iter = new int[V];
    while (true) {
        bfs(s, V, G, level);
        if (level[t] < 0) {
            delete[] level;
            delete[] iter;
            return flow;
        }
        memset(iter, 0, sizeof(*iter) * V);
        int f;
        while ((f = dfs(s, t, INF_INT, V, G, level, iter)) > 0) {
            flow += f;
        }
    }
}

#define ALGORITHMS_DINIC_H

#endif //ALGORITHMS_DINIC_H
