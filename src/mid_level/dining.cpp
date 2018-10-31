//
// Created by yuanh on 2018/6/18.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/dining.h"

int main() {
    int N = 4;
    int F = 3;
    int D = 3;
    auto **like_foods = new bool *[4]{
            new bool[3]{true, true, false},
            new bool[3]{false, true, true},
            new bool[3]{true, false, true},
            new bool[3]{true, false, true}
    };

    auto **like_drinks = new bool *[4]{
            new bool[3]{true, false, true},
            new bool[3]{true, true, false},
            new bool[3]{true, true, false},
            new bool[3]{false, false, true}
    };
    cout << "dining res : " << dining(N, F, D, like_foods, like_drinks) << endl;
    for (int i = 0; i < N; ++i) {
        delete[] like_foods[i];
        delete[] like_drinks[i];
    }
    delete[] like_foods;
    delete[] like_drinks;
    return 0;
}