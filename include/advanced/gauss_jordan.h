//
// Created by yuanhao on 18-10-8.
//

#ifndef ALGORITHMS_GAUSS_JORDAN_H

#define EPS 1e-8

#include "../mid_level/matrix.h"
#include <vector>
#include <cmath>
#include <algorithm>

using std::abs;
using std::swap;
using std::vector;

vector<double> gauss_jordan(const matrix<double> &A, const vector<double> &b) {
    int n = A.row;
    matrix<double> B(n, n + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            B[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        B[i][n] = b[i];
    }
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i; j < n; ++j) {
            if (abs(B[j][i]) > abs(B[pivot][i])) {
                pivot = j;
            }
        }
        swap(B[i], B[pivot]);
        if (abs(B[i][i]) < EPS) {
            return vector<double>();
        }
        for (int j = i + 1; j <= n; ++j) {
            B[i][j] /= B[i][i];
        }
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                for (int k = i + 1; k <= n; ++k) {
                    B[j][k] -= B[j][i] * B[i][k];
                }
            }
        }
    }
    vector<double> x((unsigned long) n);
    for (int i = 0; i < n; ++i) {
        x[i] = B[i][n];
    }
    return x;
}

#define ALGORITHMS_GAUSS_JORDAN_H

#endif //ALGORITHMS_GAUSS_JORDAN_H
