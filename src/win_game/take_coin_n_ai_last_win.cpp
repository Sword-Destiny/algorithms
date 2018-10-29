//
// Created by 袁浩 on 2018/10/29.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/base/print_utilitys.h"
#include "../../include/win_game/take_coin_n_ai_last_win.h"

int main() {
    int n = 9;
    int k = 2;
    int *a = new int[2]{1, 4};

    cout << "n: " << n << endl;
    cout << "a: (";
    print_array(cout, a, k);
    cout << ")" << endl;
    cout << "winner: ";
    cout << take_coin_n_ai_last_win(n, a, k) << endl;

    n = 10;
    cout << endl;

    cout << "n: " << n << endl;
    cout << "a: (";
    print_array(cout, a, k);
    cout << ")" << endl;
    cout << "winner: ";
    cout << take_coin_n_ai_last_win(n, a, k) << endl;
    delete[] a;
    return 0;
}