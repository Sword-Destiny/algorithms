//
// Created by yuanhao on 2019-8-28.
//

#ifndef ALGORITHMS_MAX_HAPPY_VALUE_H
#define ALGORITHMS_MAX_HAPPY_VALUE_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * 整个公司的人员结构可以看作是一棵标准的多叉树。树的头节点是公司唯一的老板，除老板外，每个员工都有唯一的直接上级，叶节点是没有任何下属的基层员工，除基层员工外，每个员工都有一个或多个直接下级，另外每个员工都有一个快乐值。
 * 这个公司现在要办 party，你可以决定哪些员工来，哪些员工不来。但是要遵循如下的原则：
 * 1.如果某个员工来了，那么这个员工的所有直接下级都不能来。
 * 2.派对的整体快乐值是所有到场员工快乐值的累加。
 * 3.你的目标是让派对的整体快乐值尽量大。
 * 给定一棵多叉树，请输出派对的最大快乐值。
 *
 * 输入描述:
 * 第一行两个整数 n 和 root，n 表示公司的总人数，root 表示公司的老板。
 * 第二行 n 个整数 happy_i 表示员工 i 的快乐值。
 * 接下来 n - 1 行每行两个整数 u_i 和 v_i 表示 u_i 是 v_i 的直接上级。
 *
 * 输出描述:
 * 输出一个整数表示最大快乐值。
 *
 * 示例1
 * 输入
 * 3 1
 * 5 1 1
 * 1 2
 * 1 3
 * 输出
 * 5
 */
void max_happy_value(int root, int *happy_value, vector<int> *tree, int &root_exists_max_value,
                     int &root_not_exists_max_value) {
    int root_happy_value = happy_value[root];

    int sub_max_sum = 0;
    int sub_not_exists_sum = 0;
    for (int i = 0; i < tree[root].size(); ++i) {
        int not_exists_value = 0;
        int exists_value = 0;
        max_happy_value(tree[root][i], happy_value, tree, exists_value, not_exists_value);
        int sub_max = max(not_exists_value, exists_value);
        sub_max_sum += sub_max;
        sub_not_exists_sum += not_exists_value;
    }
    root_exists_max_value = root_happy_value + sub_not_exists_sum;
    root_not_exists_max_value = sub_max_sum;
}

#endif //ALGORITHMS_MAX_HAPPY_VALUE_H
