//
// Created by yuanhao on 18-10-29.
//

#ifndef ALGORITHMS_EUCLID_S_GAME_H

#include <algorithm>
#include <string>

using std::string;
using std::swap;

/**
 * 给定两个整数a和b，Stan和Ollie轮流从较大数字中减去较小数字的倍数，
 * 并且相减的结果不能小于0，Stan先手。规定在自己的回合将一个数变为0的获胜。
 * 当双方都采取最优策略时，谁会获胜？
 *
 * @param a
 * @param b
 * @return
 */
string euclids_game(int a, int b) {
    bool f = true;
    for (;;) {
        if (a > b) {
            swap(a, b);
        }
        if (b % a == 0) {
            break;
        }
        if (b - a > a) {
            break;
        }
        b -= a;
        f = !f;
    }
    if (f) {
        return "Stan";
    }
    return "Ollie";
}

#define ALGORITHMS_EUCLID_S_GAME_H

#endif //ALGORITHMS_EUCLID_S_GAME_H
