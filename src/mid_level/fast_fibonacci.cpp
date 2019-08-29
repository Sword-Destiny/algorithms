//
// Created by yuanh on 2018/6/6.
//
#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/fast_fibonacci.h"

int main() {
    long long mod = 1e9 + 7;
    for (unsigned int i = 0; i < 50; ++i) {
        cout << "fast_fibonacci " << i << " : " << fast_fibonacci(i, mod) << endl;
    }
    cout << fast_fibonacci(4593613583255041, mod) << endl;
    return 0;
}
