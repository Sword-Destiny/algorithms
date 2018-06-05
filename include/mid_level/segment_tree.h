//
// Created by yuanh on 2018/6/5.
//

#ifndef ALGORITHMS_SEGMENT_TREE_H
#ifndef INF_INT
#define INF_INT 0x3fffffff
#endif

#include <algorithm>

using std::min;

template<typename T>
/**
 * 线段树
 * @tparam T 模板参数
 */
class segment_tree {
public:
    unsigned long n;//长度
    T *data; //数据

public:
    segment_tree(unsigned long _n, unsigned long max_n) : n(_n), data(new T[max_n]) {
        asm ("bsr %1,%%eax ;"
             "movl %%eax,%0 ;"
        : "=m"(n)
        : "m" (_n)
        );
        n = ((unsigned) 1) << (n + 1);
        // 上面的操作是把n变成大于_n的2次幂值
        for (unsigned long i = 0; i < n * 2 - 1; ++i) {
            data[i] = INF_INT;
        }
    }

    /**
     * 把第i个值更新为value
     * @param i
     * @param value
     */
    void update(unsigned long i, T value) {
        i += n - 1;
        data[i] = value;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    /**
     * 求[a,b)的最小值
     * @param a a
     * @param b b
     * @param i 节点编号
     * @param left 节点区间[left,right)
     * @param right 节点区间[left,right)
     * @return 最小值
     */
    T query(unsigned long a, unsigned long b, unsigned long i, unsigned long left, unsigned long right) {
        if (right <= a || b <= left) {
            return INF_INT;
        }
        if (a <= left && b >= right) {
            return data[i];
        }
        T v_left = query(a, b, i * 2 + 1, left, (left + right) / 2);
        T v_right = query(a, b, i * 2 + 2, (left + right) / 2, right);
        return min(v_left, v_right);
    }

    ~segment_tree() {
        delete[] data;
    }


};

#define ALGORITHMS_SEGMENT_TREE_H

#endif //ALGORITHMS_SEGMENT_TREE_H
