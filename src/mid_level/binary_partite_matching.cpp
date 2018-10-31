//
// Created by yuanh on 2018/6/12.
//

#include <iostream>

using std::cout;
using std::endl;

#include "mid_level/binary_partite_matching.h"

int main() {
    int C = 3;
    int T = 3;
    auto **can = new bool *[3]{
            new bool[3]{true, true, false},
            new bool[3]{true, false, true},
            new bool[3]{false, true, false},
    };
    int res = binary_partite_matching(C, T, can);
    cout << "binary_partite_matching res : " << res << endl;
    for (int i = 0; i < C; ++i) {
        delete[] can[i];
    }
    delete[] can;
    return 0;
}