//
// Created by 袁浩 on 2018-11-16.
//
#include <iostream>

using std::cout;
using std::endl;

#include "../../include/graph/strongly_connected_component.h"

int main() {
    int v = 12;
    auto *G = new vector<int>[v];
    G[11].emplace_back(10);
    G[10].emplace_back(9);
    G[10].emplace_back(7);
    G[9].emplace_back(8);
    G[8].emplace_back(7);
    G[7].emplace_back(9);
    G[8].emplace_back(6);
    G[6].emplace_back(5);
    G[5].emplace_back(4);
    G[4].emplace_back(6);
    G[5].emplace_back(3);
    G[5].emplace_back(2);
    G[3].emplace_back(2);
    G[2].emplace_back(1);
    G[1].emplace_back(2);
    G[3].emplace_back(0);

    int k = strongly_connected_component(v, G);
    cout << "strongly_connected_component res : " << k << endl;
    delete[] G;
    return 0;
}