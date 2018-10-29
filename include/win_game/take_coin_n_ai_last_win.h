//
// Created by 袁浩 on 2018/10/29.
//

#ifndef ALGORITHMS_TAKE_COIN_N_AI_LAST_WIN_H

#include <string>

using std::string;

/**
 * 硬币游戏,Alice和Bob玩一个游戏,有n枚硬币,给定k个数字,a[1]...a[k],
 * Alice和Bob轮流取硬币,每次取硬币的数量必须在a[1]...a[k]中,规定拿走最后一个硬币的人获胜.
 * 假设a[1]...a[k]中一定有1,每个人都采取最优策略,谁会获胜?
 *
 * @param n
 * @param a
 * @param k
 * @return
 */
string take_coin_n_ai_last_win(int n, const int *a, int k) {
    bool *win = new bool[n + 1];
    win[0] = false;
    for (int i = 1; i <= n; ++i) {
        win[i] = false;
        for (int j = 0; j < k; ++j) {
            win[i] |= a[j] <= i && !win[i - a[j]];
        }
    }
    bool res = win[n];
    delete[] win;
    if (res) {
        return "Alice";
    }
    return "Bob";
}

#define ALGORITHMS_TAKE_COIN_N_AI_LAST_WIN_H

#endif //ALGORITHMS_TAKE_COIN_N_AI_LAST_WIN_H
