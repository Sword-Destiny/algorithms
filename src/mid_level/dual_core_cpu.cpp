//
// Created by yuanh on 2018/6/21.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/dual_core_cpu.h"

int main() {
    int n = 3;
    int m = 1;
    auto **weights = new int *[n]{
            new int[2]{1, 10},
            new int[2]{2, 10},
            new int[2]{10, 3}
    };

    auto **trans = new int *[m]{
            new int[3]{1, 2, 1000},
    };

    cout << "dual_core_cpu res : " << dual_core_cpu(3, 1, weights, trans) << endl;

    for (int i = 0; i < n; ++i) {
        delete[] weights[i];
    }
    for (int i = 0; i < m; ++i) {
        delete[] trans[i];
    }
    delete[] weights;
    delete[] trans;
    return 0;
}