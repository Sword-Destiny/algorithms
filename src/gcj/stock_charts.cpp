//
// Created by yuanhao on 18-9-29.
//

#include "../../include/gcj/stock_charts.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 5;
    int k = 2;

    int **p = new int *[n]{
            new int[k]{1, 1},
            new int[k]{2, 2},
            new int[k]{5, 4},
            new int[k]{4, 4},
            new int[k]{4, 1}
    };
    int ans = stock_charts(n, k, p);
    cout << "stock_charts res : " << ans << endl;
    return 0;
}