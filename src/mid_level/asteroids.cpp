//
// Created by yuanh on 2018/6/17.
//

#include <iostream>

using std::cout;
using std::endl;

#include "mid_level/asteroids.h"

int main() {
    int row = 4;
    int column = 3;
    auto **can = new bool *[4]{
            new bool[3]{true, false, true},
            new bool[3]{false, true, false},
            new bool[3]{false, true, false},
            new bool[3]{false, true, false}
    };
    int res = asteroids(row, column, can);
    cout << "asteroids res : " << res << endl;
    for (int i = 0; i < row; ++i) {
        delete[] can[i];
    }
    delete[] can;
    return 0;
}