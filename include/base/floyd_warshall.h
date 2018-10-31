//
// Created by yuanh on 2018/5/24.
//

#ifndef ALGORITHMS_FLOYD_WARSHALL_H

#ifndef INF_INT
#define INF_INT 0x3fffffff
#endif

template<typename T>
inline T min(T a, T b) {
    return a < b ? a : b;
}

/**
 * 任意两点之间的最短路径
 * @param G 图
 * @param n 顶点数量
 * @param d 保存距离
 */
void floyd_warshall(int **G, int n, int **d) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = G[i][j];
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

#define ALGORITHMS_FLOYD_WARSHALL_H

#endif //ALGORITHMS_FLOYD_WARSHALL_H
