//
// Created by yuanh on 2018/6/16.
//

#ifndef ALGORITHMS_MIN_COST_FLOW_H
#ifndef INF_INT
#define INF_INT 0x3fffffff
#endif

#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using std::fill;
using std::vector;
using std::memset;
using std::priority_queue;
using std::greater;
using std::min;

/**
 * 这个数据结构是给dijkstra算法用的
 */
typedef struct _mincost_pair {
    int distance; // 距离
    int v; // 顶点
} min_pair;

bool operator<(const min_pair &d1, const min_pair &d2) {
    return d1.distance < d2.distance;
}

bool operator>(const min_pair &d1, const min_pair &d2) {
    return d1.distance > d2.distance;
}

typedef struct _mincost_edge {
    int to; // 目的顶点
    int capacity; // 链路容量
    int cost; // 单位代价
    int reverse; // 反边
} min_edge;

void add_edge(vector<min_edge> *G, int from, int to, int capacity, int cost) {
    G[from].emplace_back((min_edge) {to, capacity, cost, (int) G[to].size()});
    G[to].emplace_back((min_edge) {from, 0, -cost, (int) (G[from].size() - 1)});
}

/**
 * 流最小代价算法
 * @param s 源顶点
 * @param t 目的顶点
 * @param flow 流
 * @param V 顶点总数
 * @param G 图
 * @return 传递flow需要的最小代价
 */
int min_cost_flow(int s, int t, int flow, int V, vector<min_edge> *G) {
    auto *h = new int[V]; // 势
    auto *distance = new int[V]; // 最短距离
    auto *prev_vertex = new int[V]; // 前驱结点
    auto *prev_edge = new int[V]; // 前驱结点对应的边
    int res = 0;
    memset(h, 0, V * sizeof((*h)));
    while (flow > 0) {
        priority_queue<min_pair, vector<min_pair>, greater<min_pair>> que;
        fill(distance, distance + V, INF_INT);
        distance[s] = 0;
        que.push((min_pair) {0, s});
        while (!que.empty()) {
            min_pair p = que.top();
            que.pop();
            int v = p.v;
            if (distance[v] < p.distance) { continue; }
            for (int i = 0; i < G[v].size(); ++i) {
                min_edge &e = G[v][i];
                if (e.capacity > 0 && distance[e.to] > distance[v] + e.cost + h[v] - h[e.to]) {
                    distance[e.to] = distance[v] + e.cost + h[v] - h[e.to];
                    prev_vertex[e.to] = v;
                    prev_edge[e.to] = i;
                    que.push((min_pair) {distance[e.to], e.to});
                }
            }
        }
        if (distance[t] == INF_INT) {
            return -1;
        }
        for (int v = 0; v < V; ++v) {
            h[v] += distance[v];
        }
        int d = flow;
        for (int v = t; v != s; v = prev_vertex[v]) {
            d = min(d, G[prev_vertex[v]][prev_edge[v]].capacity);
        }
        flow -= d;
        res += d * h[t];
        for (int v = t; v != s; v = prev_vertex[v]) {
            min_edge &e = G[prev_vertex[v]][prev_edge[v]];
            e.capacity -= d;
            G[v][e.reverse].capacity += d;
        }
    }
    return res;
}

#define ALGORITHMS_MIN_COST_FLOW_H

#endif //ALGORITHMS_MIN_COST_FLOW_H
