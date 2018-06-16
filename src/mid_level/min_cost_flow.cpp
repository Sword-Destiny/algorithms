//
// Created by yuanh on 2018/6/16.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/min_cost_flow.h"

int main() {
    int flow = 9;
    int v = 5;
    auto *G = new vector<min_edge>[v];
    auto *G_res = new vector<min_edge>[v];
    add_edge(G, 0, 1, 10, 2);
    add_edge(G, 0, 2, 2, 4);
    add_edge(G, 1, 2, 6, 6);
    add_edge(G, 1, 3, 6, 2);
    add_edge(G, 3, 2, 3, 3);
    add_edge(G, 3, 4, 8, 6);
    add_edge(G, 2, 4, 5, 2);
    add_edge(G_res, 0, 1, 10, 2);
    add_edge(G_res, 0, 2, 2, 4);
    add_edge(G_res, 1, 2, 6, 6);
    add_edge(G_res, 1, 3, 6, 2);
    add_edge(G_res, 3, 2, 3, 3);
    add_edge(G_res, 3, 4, 8, 6);
    add_edge(G_res, 2, 4, 5, 2);
    int min_cost = min_cost_flow(0, 4, flow, v, G_res);
    cout << "flow : " << flow << " , min cost : " << min_cost << endl;
    flow = 11;
    min_cost = min_cost_flow(0, 4, flow, v, G);
    cout << "flow : " << flow << " , min cost : " << min_cost << endl;
    delete[] G;
    delete[] G_res;
    return 0;
}