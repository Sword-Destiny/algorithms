//
// Created by 袁浩 on 2018-11-13.
//

#include <iostream>
#include "../../include/win_game/staircase_nim.h"

using std::cout;
using std::endl;

int main() {
    int n = 8;
    int *p = new int[8]{1, 5, 6, 7, 9, 12, 14, 17};
    string winner = staircase_nim(p, n);
    cout << "staircase_nim winner : " << winner << endl;
    delete[] p;
    return 0;
}