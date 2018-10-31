//
// Created by yuanh on 2018/5/25.
//

#ifndef ALGORITHMS_MAP_EDGE_H
#define ALGORITHMS_MAP_EDGE_H

typedef struct _map_edge {
    int from;
    int to;
    int weight;
} map_edge;

bool operator<(const map_edge &e1, const map_edge &e2) {
    return e1.weight < e2.weight;
}

#endif //ALGORITHMS_MAP_EDGE_H
