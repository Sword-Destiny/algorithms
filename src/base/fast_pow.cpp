//
// Created by yuanh on 2018/5/28.
//
#include "../include/fast_pow.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    cout << "10^9 = " << fast_pow(10, 9) << endl;
    cout << "(-3)^11 = " << fast_pow(-3, 11) << endl;
    return 0;
}
