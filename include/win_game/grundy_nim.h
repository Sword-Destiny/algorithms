//
// Created by 袁浩 on 2018-11-15.
//

#ifndef ALGORITHMS_GRUNDY_NIM_H
#define ALGORITHMS_GRUNDY_NIM_H

#include <string>

using std::string;

#include <algorithm>

using std::max_element;

#include <set>

using std::set;

/**
 * Alice和Bob玩游戏，给定k个数字a1-ak，一开始有n堆硬币，每堆各有xi枚硬币，
 * Alice和Bob轮流选出一堆硬币，从中取出一些硬币，每次所取的硬币的枚数必须是在ai中，
 * Alice先取，取光硬币的一方获胜，当双方都采取最优策略时，谁会获胜？（ai中必定有1）
 */
string grundy_nim(int n, int k, const int *a, const int *x) {
    int max_x = *max_element(x, x + n);
    auto grundy = new int[max_x + 1];
    grundy[0] = 0;
    for (int j = 1; j <= max_x; ++j) {
        set<int> s;
        for (int i = 0; i < k; ++i) {
            if (a[i] <= j) {
                s.insert(grundy[j - a[i]]);
            }
        }
        int g = 0;
        while (s.count(g) != 0) {
            g++;
        }
        grundy[j] = g;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res ^= grundy[x[i]];
    }
    delete[] grundy;
    if (res != 0) {
        return "Alice";
    }
    return "Bob";
}

#endif //ALGORITHMS_GRUNDY_NIM_H
