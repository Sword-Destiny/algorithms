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
 *
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
