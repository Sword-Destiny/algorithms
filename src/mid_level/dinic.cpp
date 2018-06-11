//
// Created by yuanh on 2018/6/11.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/dinic.h"

int main() {
    int v = 5;
    vector<di_edge> *G = new vector<di_edge>[v];
    vector<di_edge> *G_res = new vector<di_edge>[v];
    add_edge(G, 0, 1, 10);
    add_edge(G, 0, 2, 2);
    add_edge(G, 1, 2, 6);
    add_edge(G, 1, 3, 6);
    add_edge(G, 3, 2, 3);
    add_edge(G, 3, 4, 8);
    add_edge(G, 2, 4, 5);
    add_edge(G_res, 0, 1, 10);
    add_edge(G_res, 0, 2, 2);
    add_edge(G_res, 1, 2, 6);
    add_edge(G_res, 1, 3, 6);
    add_edge(G_res, 3, 2, 3);
    add_edge(G_res, 3, 4, 8);
    add_edge(G_res, 2, 4, 5);
    int flow = dinic_max_flow(0, 4, G_res, v);
    cout << "dinic max flow : " << flow << endl;
    delete[] G;
    delete[] G_res;
    return 0;
}