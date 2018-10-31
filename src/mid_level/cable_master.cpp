//
// Created by yuanh on 2018/5/29.
//

#include "../../include/mid_level/cable_master.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;
using std::setiosflags;
using std::ios;

int main() {
    int N = 4;
    int K = 11;
    double L[4] = {8.02, 7.43, 4.57, 5.39};
    double a = 0.01;
    double res = cable_master(N, K, L, a);
    cout << "cable master : " << setiosflags(ios::fixed) << setprecision(2) << res << endl;
    return 0;
}