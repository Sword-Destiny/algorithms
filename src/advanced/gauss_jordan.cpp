//
// Created by yuanhao on 18-10-8.
//

#include "../../include/advanced/gauss_jordan.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    auto **A = new double *[3]{
            new double[3]{1, -2, 3},
            new double[3]{4, -5, 6},
            new double[3]{7, -8, 10}
    };
    vector<double> b = {6, 12, 21};
    matrix<double> m(3, 3, A);
    vector<double> x = gauss_jordan(m, b);
    cout << "gauss_jordan x : ";
    for (int i = 0; i < 3; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; ++i) {
        delete[] A[i];
    }
    delete[] A;
    return 0;
}