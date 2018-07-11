//
// Created by sworddestiny on 18-7-11.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/jack_straws.h"

int main() {
    int n = 4;
    auto **pq = new Point *[n]{
            new Point[2]{Point{0, 4}, Point{4, 1}},
            new Point[2]{Point{0, 1}, Point{2, 3}},
            new Point[2]{Point{1, 2}, Point{3, 4}},
            new Point[2]{Point{1, 0}, Point{2, 1}},
    };
    int m = 4;
    auto **ab = new int *[m]{
            new int[2]{0, 1},
            new int[2]{0, 3},
            new int[2]{1, 2},
            new int[2]{1, 3},
    };
    auto *res = new string[m];
    jack_straws(n,m,pq,ab,res);
    for (int i = 0; i < m; ++i) {
        cout << res[i] << endl;
    }
    delete[] res;
    for (int i = 0; i < m; ++i) {
        delete[] ab[i];
    }
    delete[] ab;
    for (int i = 0; i < n; ++i) {
        delete[] pq[i];
    }
    delete[] pq;
    return 0;
}