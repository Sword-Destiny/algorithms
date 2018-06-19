//
// Created by yuanh on 2018/6/19.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/orthogonal_latin_squares.h"

int main() {
    // 正交拉丁方的问题其解空间很大,10x10的矩阵在i7-7700k上可能要运行半个小时,请使用小一点的矩阵进行测试
    int n = 10;
    auto **a = new int *[n]{
            new int[n]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
            new int[n]{1, 8, 3, 2, 5, 4, 7, 6, 9, 0},
            new int[n]{2, 9, 5, 6, 3, 0, 8, 4, 7, 1},
            new int[n]{3, 7, 0, 9, 8, 6, 1, 5, 2, 4},
            new int[n]{4, 6, 7, 5, 2, 9, 0, 8, 1, 3},
            new int[n]{5, 0, 9, 4, 7, 8, 3, 1, 6, 2},
            new int[n]{6, 5, 4, 7, 1, 3, 2, 9, 0, 8},
            new int[n]{7, 4, 1, 8, 0, 2, 9, 3, 5, 6},
            new int[n]{8, 3, 6, 0, 9, 1, 5, 2, 4, 7},
            new int[n]{9, 2, 8, 1, 6, 7, 4, 0, 3, 5}
    };
    matrix<int> m(n, n, a);
    matrix<int> res = orthogonal_latin_squares(m);
    cout << "orthogonal_latin_squares res : " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // 一个可能的解,书中说只有这一个解,我没有验证
    // 0 2 8 5 9 4 7 3 6 1
    // 1 7 4 9 3 6 5 0 2 8
    // 2 5 6 4 8 7 0 1 9 3
    // 3 6 9 0 4 5 8 2 1 7
    // 4 8 1 7 5 3 6 9 0 2
    // 5 1 7 8 0 2 9 4 3 6
    // 6 9 0 2 7 1 3 8 4 5
    // 7 3 5 1 2 0 4 6 8 9
    // 8 0 2 3 6 9 1 7 5 4
    // 9 4 3 6 1 8 2 5 7 0
    // 如果不要求两个矩阵第一列相等,而是要求第一行相等,则有另一个存在的解
    // 0 1 2 3 4 5 6 7 8 9
    // 9 6 5 4 7 8 3 0 1 2
    // 1 3 8 5 2 6 0 9 4 7
    // 7 8 4 0 5 3 2 1 9 6
    // 5 2 9 6 3 7 8 4 0 1
    // 3 9 6 2 0 1 4 5 7 8
    // 8 4 0 1 6 9 7 2 5 3
    // 6 7 3 9 1 0 5 8 2 4
    // 2 0 1 7 8 4 9 6 3 5
    // 4 5 7 8 9 2 1 3 6 0
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}