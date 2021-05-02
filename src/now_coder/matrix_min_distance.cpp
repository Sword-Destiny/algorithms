//
// Created by yuanhao on 2019-8-26.
//

#include "../../include/now_coder/matrix_min_distance.h"

int main() {
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    int **matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << matrix_min_distance(n, m, matrix) << endl;
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}