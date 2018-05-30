//
// Created by yuanh on 2018/5/30.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/aggressive_cows.h"

int main() {
    int n = 5;
    int m = 3;
    int ns[5] = {1, 2, 8, 4, 9};
    int res[3] = {-1, -1, -1};
    int d = aggressive_cows(n, m, ns, res);
    cout << "aggressive cows d : " << d << endl;
    cout << "res : ";
    for (int i = 0; i < m; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}