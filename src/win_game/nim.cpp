//
// Created by 袁浩 on 2018/10/31.
//

#include <iostream>
#include "../../include/base/print_utilitys.h"

using std::cout;
using std::endl;

#include "../../include/win_game/nim.h"

int main() {
    int n = 3;
    int a[3] = {1, 2, 4};
    cout << "array: ";
    print_array(cout, a, n);
    cout << endl;
    cout << "nim winner: " << nim(a, n) << endl;
    return 0;
}