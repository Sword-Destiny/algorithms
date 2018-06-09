//
// Created by yuanh on 2018/6/9.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/traveller_problem.h"

int main() {
    int n = 5;
    auto **d = new long *[5]{
            new long[5]{0, 3, INF_INT, 4, INF_INT},
            new long[5]{INF_INT, 0, 5, INF_INT, INF_INT},
            new long[5]{4, INF_INT, 0, 5, INF_INT},
            new long[5]{INF_INT, INF_INT, INF_INT, 0, 3},
            new long[5]{7, 6, INF_INT, INF_INT, 0}
    };
    long res = traveller_problem(n, d);
    cout << "traveller_problem min road : " << res << endl;
    for (int i = 0; i < n; ++i) {
        delete[] d[i];
    }
    delete[] d;
    return 0;
}