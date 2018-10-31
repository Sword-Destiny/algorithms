//
// Created by yuanh on 2018/5/28.
//

#ifndef ALGORITHMS_BRIBE_PRISONERS_H

#ifndef INF_INT
#define INF_INT 0x3fffffff
#endif

#include <algorithm>
#include <cstring>

using std::min;
using std::memcpy;

/**
 * 区间动态规划
 * bribe the prisoner
 * POJ 2019 Round 1C C
 * 我不确定这道题是否还存在更好的贪心的方法,因为我觉得先释放中间的囚犯比释放两边的囚犯花费更少,也许不需要动态规划直接分治法就搞定了
 * @param P 存放罪犯的数组
 * @param Q 释放罪犯的数量
 * @param ps 释放罪犯的列表
 * @return 花费的最少金币,但是不能保存释放顺序,如要记录释放顺序,需要使用递归方法
 */
int bribe_prisoners(int P, int Q, int *ps) {
    auto **dp = new int *[Q + 1]; //定义一个二维数组。依次用来填充最小的花费。表示从第i个填充到j个时的最小花费
    for (int i = 0; i < Q + 1; ++i) {
        dp[i] = new int[Q + 2];
    }
    auto *a = new int[Q + 2];
    memcpy(a + 1, ps, Q * sizeof(int));
    a[0] = 0;
    a[Q + 1] = P + 1;//为了解决边界问题。
    for (int i = 0; i <= Q; i++) {
        dp[i][i + 1] = 0;//初始化，因为所有的从i到i+1的花费除去边界都是0；
    }
    //循环求解。定义w表示区间的范围，w=2表示跨度为2的情况，也就是该区间里面只有一个要释放的犯人
    for (int w = 2; w <= Q + 1; w++) {
        //每次选的范围都是w，从i到j 的范围内的最小值等于从i到K加从第k到j的最小值。
        for (int i = 0; i + w <= Q + 1; i++) {
            int j = i + w;//此处用到的k恰是其中的中值。
            int tmp = INF_INT;//tmp用来保存当前区间的当前最好情况的花费金币数
            for (int k = i + 1; k < j; k++) {
                tmp = min(tmp, dp[i][k] + dp[k][j]);
            }
            dp[i][j] = tmp + a[j] - a[i] - 2;//此处就是当前区间最小值。
        }
    }
    int res = dp[0][Q + 1];
    delete[] a;
    for (int i = 0; i < Q + 1; ++i) {
        delete[] dp[i];
    }
    delete[] dp;
    return res;
}

#define ALGORITHMS_BRIBE_PRISONERS_H

#endif //ALGORITHMS_BRIBE_PRISONERS_H
