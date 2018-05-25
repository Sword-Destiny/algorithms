//
// Created by yuanh on 2018/5/25.
//

#ifndef ALGORITHMS_UNION_FIND_H

#include <cstring>
using std::memcpy;

/**
 * 并查集
 */
typedef class union_find_set {
public:
    int *parent;
    int *rank;
    int n;
public:
    explicit union_find_set(int n) : n(n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    union_find_set(const union_find_set &uf) : n(uf.n) {
        parent = new int[n];
        rank = new int[n];
        memcpy(parent, uf.parent, n * sizeof(int));
        memcpy(rank, uf.rank, n * sizeof(int));
    }

    union_find_set &operator=(const union_find_set &uf) {
        n = uf.n;
        memcpy(parent, uf.parent, n * sizeof(int));
        memcpy(rank, uf.rank, n * sizeof(int));
        return *this;
    }

    ~union_find_set() {
        delete[] parent;
        delete[] rank;
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            return parent[x] = find(parent[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
} union_set;

#define ALGORITHMS_UNION_FIND_H

#endif //ALGORITHMS_UNION_FIND_H
