//
// Created by 袁浩 on 2018-11-13.
//

#ifndef ALGORITHMS_STAIRCASE_NIM_H
#define ALGORITHMS_STAIRCASE_NIM_H

#include <string>
#include <algorithm>
#include <cstring>

using std::memcpy;
using std::string;
using std::sort;

/**
 * 排成直线的格子上放有n个棋子.棋子i在左数第pi个格子上.Georgia和Bob
 * 轮流选择一个棋子向左移动.每次可以移动一格及以上任意多格,但是不允许反超其他的棋子,
 * 也不允许将两个棋子放在同一个格子内.无法进行移动操作的一方视为失败.
 * 假设Georgia先进行移动,当双方都采取最优策略时,谁会获胜?
 */
string staircase_nim(int *p, int n) {
    int *q = new int[n + 1]; // 如果p的长度是奇数那么就需要加一
    memcpy(q, p, sizeof(int) * n);
    p = q;
    if (n % 2 == 1) {
        p[n++] = 0;
    }
    sort(p, p + n);
    int x = 0;
    for (int i = 0; i < n - 1; i += 2) {
        x ^= (p[i + 1] - p[i] - 1);
    }
    if (x == 0) {
        delete[] p;
        return "Bob";
    }
    delete[] p;
    return "Georgia";
}

#endif //ALGORITHMS_STAIRCASE_NIM_H
