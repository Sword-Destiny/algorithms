//
// Created by yuanhao on 18-10-29.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/win_game/euclid's_game.h"

int main() {
    int a = 34, b = 12;
    cout << euclids_game(a, b) << endl;
    a = 15, b = 24;
    cout << euclids_game(a, b) << endl;
    return 0;
}