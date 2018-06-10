//
// Created by yuanh on 2018/6/10.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/ford_fulkerson.h"

int main() {
    int v = 5;
    vector<ff_edge> *G = new vector<ff_edge>[v];
    vector<ff_edge> *G_res = new vector<ff_edge>[v];
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
    int flow = ford_fulkerson(G_res, v, 0, 4);
    cout << "ford_fulkerson max flow : " << flow << endl;
    delete[] G;
    delete[] G_res;
    return 0;
}