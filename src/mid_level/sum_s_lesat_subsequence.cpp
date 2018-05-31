//
// Created by yuanh on 2018/5/31.
//
#include "../../include/mid_level/sum_s_lesat_subsequence.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 10;
    int s = 15;
    int a[10] = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
    int begin = 0, end = 0;
    int res = sum_s_lesat_subsequence(a, n, s, begin, end);
    cout << "sum_s_lesat_subsequence res : " << res << endl;
    cout << "begin : " << begin << endl;
    cout << "end : " << end << endl;
    return 0;
}
