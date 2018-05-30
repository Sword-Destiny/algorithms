//
// Created by yuanh on 2018/5/30.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/max_average.h"

int main() {
    int k = 2;
    int n = 3;
    double w[3] = {2, 5, 2};
    double v[3] = {2, 3, 1};
    max_average_s res[3] = {};
    cout << "max average : " << max_average(k, n, v, w, res) << endl;
    for (int i = 0; i < k; ++i) {
        cout << "w : " << res[i].w << ", v : " << res[i].v << endl;
    }
    return 0;
}