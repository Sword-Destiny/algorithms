//
// Created by yuanh on 2018/5/24.
//

#include <iostream>
#include "../include/dijkstra.h"

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
    G[2][4] = 1;
    G[3][4] = 1;
    G[6][3] = 1;
    G[5][6] = 1;
    G[7][5] = 1;
    G[9][7] = 1;
    G[8][9] = 1;
    G[0][8] = 1;
    G[0][1] = 1;
    G[2][8] = 1;
    auto *d = new int[n];
    auto *prev = new int[n];
    dijkstra(G, n, 0, d, prev);
    cout << "d: "; // d: 0 1 2 3 3 4 5 3 1 2
    for (int i = 0; i < n; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
    cout << "prev: "; // d: 0 1 2 3 3 4 5 3 1 2
    for (int i = 0; i < n; ++i) {
        cout << prev[i] << " ";
    }
    cout << endl;
    delete[] d;
    delete[] prev;
    for (int i = 0; i < n; ++i) {
        delete[] G[i];
    }
    delete[] G;
    return 0;
}