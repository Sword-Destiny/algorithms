//
// Created by 袁浩 on 2018-11-16.
//

#ifndef ALGORITHMS_STRONGLY_CONNECTED_COMPONENT_H
#define ALGORITHMS_STRONGLY_CONNECTED_COMPONENT_H

#include <vector>
#include <cstring>

using std::vector;
using std::memset;

/**
 * 第二次反向遍历
 */
void rdfs(int &v, int k, bool *used, vector<int> *rG, int *cmp) {
    used[v] = true;
    cmp[v] = k;
    for (int &from:rG[v]) {
        if (!used[from]) {
            rdfs(from, k, used, rG, cmp);
        }
    }
}

/**
 * 第一次遍历
 */
void dfs(int &v, bool *used, vector<int> *G, vector<int> &vs) {
    used[v] = true;
    for (int &to :G[v]) {
        if (!used[to]) {
            dfs(to, used, G, vs);
        }
    }
    vs.emplace_back(v);
}

/**
 * 边反转
 */
void reverse_edges(int V, vector<int> *G, vector<int> *rG) {
    for (int from = 0; from < V; ++from) {
        for (int &to:G[from]) {
            rG[to].emplace_back(from);
        }
    }
}

/**
 * 强连通分量分解
 */
int strongly_connected_component(int V, vector<int> *G) {

    auto *rG = new vector<int>[V]; // 边反向
    vector<int> vs; // 后续遍历的顶点列表
    bool *used = new bool[V]; // 访问标记
    int *cmp = new int[V]; // 所属强连通分量的拓扑序

    reverse_edges(V, G, rG);
    memset(cmp, 0, sizeof(*cmp) * V);

    memset(used, 0, sizeof(*used) * V);
    for (int v = 0; v < V; ++v) {
        if (!used[v]) {
            dfs(v, used, G, vs);
        }
    }
    memset(used, 0, sizeof(*used) * V);
    int k = 0;
    for (long v = vs.size() - 1; v >= 0; --v) {
        if (!used[vs[v]]) {
            rdfs(vs[v], k++, used, rG, cmp);
        }
    }
    delete[] cmp;
    delete[] used;
    delete[] rG;
    return k;
}


#endif //ALGORITHMS_STRONGLY_CONNECTED_COMPONENT_H
