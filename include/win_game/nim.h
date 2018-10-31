//
// Created by 袁浩 on 2018/10/31.
//

#ifndef ALGORITHMS_NIM_H
#define ALGORITHMS_NIM_H

#include <string>

using std::string;

string nim(const int *a, int n) {
    int x = 0;
    for (int i = 0; i < n; ++i) {
        x ^= a[i];
    }
    if (x != 0) {
        return "Alice";
    }
    return "Bob";
}

#endif //ALGORITHMS_NIM_H
