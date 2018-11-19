//
// Created by yuanhao on 18-11-19.
//

#ifndef ALGORITHMS_LOWEST_COMMON_ANCESTOR_H
#define ALGORITHMS_LOWEST_COMMON_ANCESTOR_H

#include "tree.h"

template<typename T>
/**
 * 求最接近的公共父节点
 *
 * @tparam T
 * @param root 根节点
 * @param one 节点1
 * @param two 节点2
 */
const tree<T> *lowest_common_ancestor(const tree<T> *root, const tree<T> *one, const tree<T> *two) {
    int depth1 = root->depth(one);
    int depth2 = root->depth(two);
    if (depth1 == -1 || depth2 == -1) {
        return NULL;
    }
    if (depth1 > depth2) {
        while (depth1 > depth2) {
            one = one->parent;
            depth1--;
        }
    } else if (depth1 < depth2) {
        while (depth1 < depth2) {
            two = two->parent;
            depth2--;
        }
    }

    while (one != two) {
        one = one->parent;
        two = two->parent;
    }
    return one; // 或者返回two;
}

#endif //ALGORITHMS_LOWEST_COMMON_ANCESTOR_H
