//
// Created by yuanh on 2018/5/24.
//

#ifndef ALGORITHMS_DIJKSTRA_H
#ifndef INF_INT
#define INF_INT 0x3fffffff
#endif

#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;
using std::greater;

typedef struct _dijkstra_pair {
    int point;
    int distance;
} dijkstra_pair;

bool operator<(const dijkstra_pair &d1, const dijkstra_pair &d2) {
    return d1.distance < d2.distance;
}

bool operator>(const dijkstra_pair &d1, const dijkstra_pair &d2) {
    return d1.distance > d2.distance;
}

/**
 * 迪杰斯特拉算法,使用优先权队列
 * @param G 图
 * @param n 顶点数量
 * @param start_point 起始顶点
 * @param d 保存结果距离
 * @param prev 前驱节点用于路径还原
 */
void dijkstra(int **G, int n, int start_point, int *d, int *prev) {
    for (int i = 0; i < n; ++i) {
        d[i] = INF_INT;
        prev[i] = -1;
    }
    d[start_point] = 0;
    priority_queue<dijkstra_pair, vector<dijkstra_pair>, greater<dijkstra_pair>> que;
    que.push({start_point, 0});
    while (!que.empty()) {
        dijkstra_pair p = que.top();
        que.pop();

        int v = p.point;

        if (d[v] < p.distance) {
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (d[i] > d[v] + G[v][i]) {
                d[i] = d[v] + G[v][i];
                que.push({i, d[i]});
                prev[i] = v;
            }
        }
    }
}

#define ALGORITHMS_DIJKSTRA_H

#endif //ALGORITHMS_DIJKSTRA_H
