//
// Created by yuanh on 2018/6/8.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/matrix_power_series.h"

int main() {
    matrix<long long> m(2, 2);
    m[0][0] = 0;
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 1;
    long long mod = 0x3fffffffffffffff;
    int k = 2;
    matrix<long long> res = matrix_power_series(m, k, mod);
    cout << "matrix_power_series k : " << k << endl;
    cout << "m\n" << m << endl;
    cout << "res\n" << res << endl;
    return 0;
}