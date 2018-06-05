//
// Created by yuanh on 2018/6/4.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/mid_level/four_sum_zero.h"

int main() {
    long n = 6;
    int as[6] = {-45, -41, -36, -36, 26, -32};
    int bs[6] = {22, -27, 53, 30, -38, -54};
    int cs[6] = {42, 56, -37, -75, -10, -6};
    int ds[6] = {-16, 30, 77, -46, 62, 45};
    auto *answers = new four_sum_zero_answer<int>[6 * 6 * 6 * 6];
    long res = four_sum_zero(as, bs, cs, ds, n, answers);
    cout << "four_sum_zero res : " << res << endl;
    cout << "a\tb\tc\td\t" << endl;
    for (int i = 0; i < res; ++i) {
        cout << answers[i].a << "\t" << answers[i].b << "\t" << answers[i].c << "\t" << answers[i].d << "\t" << endl;
    }
    delete[] answers;
    return 0;
}