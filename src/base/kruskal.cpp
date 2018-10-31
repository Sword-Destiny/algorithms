//
// Created by yuanh on 2018/5/25.
//
#include "../../include/base/kruskal.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 10;
    auto G = new int *[n];
    for (int i = 0; i < n; ++i) {
        G[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            G[i][j] = INF_INT;
        }
    }
    G[1][2] = 1;
    G[2][3] = 1;
    G[2][4] = 4;
    G[3][4] = 2;
    G[6][3] = 1;
    G[5][6] = 1;
    G[7][5] = 1;
    G[9][7] = 1;
    G[8][9] = 1;
    G[0][8] = 1;
    G[0][1] = 1;
    G[2][8] = 1;
    int min_cost = 0;
    auto *res_edges = new map_edge[n - 1];
    kruskal(G, n, min_cost, res_edges);
    for (int i = 0; i < n - 1; ++i) {
        cout << res_edges[i].from << "->" << res_edges[i].to << " : " << res_edges[i].weight << endl;
    }
    cout << "min tree cost :" << min_cost << endl;
    for (int i = 0; i < n; ++i) {
        delete[] G[i];
    }
    delete[] G;
    delete[] res_edges;
    return 0;
}
