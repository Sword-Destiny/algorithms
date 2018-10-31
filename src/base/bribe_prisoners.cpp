//
// Created by yuanh on 2018/5/28.
//

#include "../../include/base/bribe_prisoners.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int P = 20;
    int Q = 3;
    int ps[3] = {3, 6, 14};
    int res = bribe_prisoners(P, Q, ps);
    cout << "bribe prisoners min cost : " << res << endl;
    return 0;
}