//
// Created by yuanh on 2018/6/5.
//

#ifndef ALGORITHMS_BINARY_INDEX_TREE_H

#include <cstring>

using std::memset;

template<typename T>
/**
 * 树状数组
 * @tparam T 类型模板
 */
class binary_indexed_tree {
public:
    int n;
    T *data;
public:
    binary_indexed_tree(int n, int max_n) : n(n), data(new T[max_n + 1]) {
        memset(data, 0, sizeof(*data) * (max_n + 1));
    }

    ~binary_indexed_tree() {
        delete[] data;
    }

public:
    /**
     * 求和
     * @param i data[0,i)的和
     * @return 和
     */
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += data[i];
            i -= i & (-i);
        }
        return s;
    }

    /**
     * 将data[i]加上value
     * @param i i
     * @param value value
     */
    void add(int i, T value) {
        while (i <= n) {
            data[i] += value;
            i += i & (-i);
        }
    }
};

template<typename T>
using bi_tree = binary_indexed_tree<T>;

#define ALGORITHMS_BINARY_INDEX_TREE_H

#endif //ALGORITHMS_BINARY_INDEX_TREE_H
