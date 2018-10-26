//
// Created by 袁浩 on 2018/10/26.
//

#include "../../include/advanced/color_stone.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {
    long long mod = 1000000007;
    long long n = 4, m = 2;
    cout << "color_stone(n m mod) -> res: (" << n << " " << m << " " << mod << ") -> " << color_stone(n, m, mod) << endl;
    n = 4, m = 10;
    cout << "color_stone(n m mod) -> res: (" << n << " " << m << " " << mod << ") -> " << color_stone(n, m, mod) << endl;
    n = 1000000000, m = 1000000000;
    cout << "color_stone(n m mod) -> res: (" << n << " " << m << " " << mod << ") -> " << color_stone(n, m, mod) << endl;
}