//
// Created by 袁浩 on 2018-11-15.
//

#include <iostream>
#include "../../include/win_game/grundy_nim.h"

using std::cout;
using std::endl;

int main() {
    int n = 3;
    int k = 3;
    int a[3] = {1, 3, 4};
    int x[3] = {5, 6, 7};

    string res = grundy_nim(n, k, a, x);
    cout << "grundy_nim winner : " << res << endl;

    x[2] = 8;
    res = grundy_nim(n, k, a, x);
    cout << "grundy_nim winner : " << res << endl;

    return 0;
}