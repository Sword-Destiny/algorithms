//
// Created by yuanh on 2018/5/28.
//

#include "../include/minimum_scalar_product.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 3;
    int v1[3] = {1, 3, -5};
    int v2[3] = {-2, 4, 1};
    int res = minimum_scalar_product(v1, v2, n);
    cout << "v1 : ";
    for (int i = 0; i < n; ++i) {
        cout << v1[i] << " ";
    }
    cout << endl;
    cout << "v2 : ";
    for (int i = 0; i < n; ++i) {
        cout << v2[i] << " ";
    }
    cout << endl;
    cout << "minimum scalar product : " << res << endl;
}