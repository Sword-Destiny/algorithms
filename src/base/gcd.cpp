//
// Created by 袁浩 on 2018/10/24.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/base/gcd.h"

int main() {
    int a = 5;
    int m = 29;

    int x = mod_inverse(a, m);
    cout << "mod_inverse : " << a << "对" << m << "求逆元的结果是 : " << x << endl;
}