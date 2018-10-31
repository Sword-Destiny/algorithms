//
// Created by yuanh on 2018/6/22.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/farm_tour.h"

int main() {
    int n = 4;
    int m = 5;
    auto **params = new int *[m]{
            new int[3]{0, 1, 1},
            new int[3]{1, 2, 1},
            new int[3]{2, 3, 1},
            new int[3]{0, 2, 2},
            new int[3]{1, 3, 2},
    };
    cout << "farm_tour res : " << farm_tour(n, m, params) << endl;
    for (int i = 0; i < m; ++i) {
        delete[] params[i];
    }
    delete[] params;
    return 0;
}