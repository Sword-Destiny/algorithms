//
// Created by yuanh on 2018/6/23.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/the_windys.h"

int main() {
    int n = 3;
    int m = 4;
    auto **weights = new int *[n]{
            new int[m]{1, 100, 100, 100},
            new int[m]{99, 1, 99, 99},
            new int[m]{98, 98, 1, 98}
    };
    cout << "the_windys res: " << the_windys(n, m, weights) << endl;
    for (int i = 0; i < n; ++i) {
        delete[] weights[i];
    }
    delete[] weights;
    return 0;
}