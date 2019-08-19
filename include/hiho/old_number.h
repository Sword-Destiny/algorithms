//
// Created by yuanhao on 2019-8-15.
//

#ifndef ALGORITHMS_OLD_NUMBER_H
#define ALGORITHMS_OLD_NUMBER_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
#define MAX_N 201

int compute_remainder(char *s, int n, int x);

/**
 * 描述
 * 小Hi有一张纸条，上面写着一个长度为N的整数。由于年代过于久远，其中有些位置已经看不清了，我们用'?'来代替这个位置。小Hi印象中记得这个数字除以X的余数为Y，他想知道这个数最小可能是多少？
 * 注意这个整数的首位不能是0，除非它本身等于0。
 * 输入
 * 第1行：1个长度为N的字符串，只包含数字0~9和'?'，1≤N≤200
 * 第2行：两个整数，X和Y，1≤X≤200,000，0≤Y＜X
 * 输出
 * 第1行：若存在解，则输出最小可能的数字，否则输出No solution
 * 样例输入
 * 10?4
 * 12 0
 * 样例输出
 * 1044
 */
void old_number(char *s, int n, vector<int> unknown_number_index, const int x, const int y) {
    // 数位dp的思想：
    // 如果第i个未知数字等于0的时候余数是r，后面第i+1到n-1的未知数字所有的情况都尝试了都没有成功，
    // 当第i个未知数字尝试为1的时候，如果余数还是r，那后面的数字任何情况都一定不能成功。
    // dp数组中第一个下标表示遍历到第i位，第二个下标表示余数
    // 当然我的算法里面，实际上余数是偏移了1的，即我记录的是上一个余数，但是结果是一样的，因为余数是循环的。
    // 如果严格的话，请将循环修改一下，先更新try_number，再计算余数。
    bool dp[unknown_number_index.size()][x + 1];
    for (int i = 0; i < unknown_number_index.size(); ++i) {
        memset(dp[i], 0, sizeof(bool) * (x + 1));
    }
    int try_number[unknown_number_index.size()];
    memset(try_number, 0, sizeof(int) * unknown_number_index.size());
    // 第一位一般不能为0，除非数字只有一位
    if (unknown_number_index[0] == 0 && n != 1) {
        try_number[0] = 1;
    }
    for (; try_number[0] < 10;) {
        for (int i = 0; i < unknown_number_index.size(); ++i) {
            s[unknown_number_index[i]] = try_number[i] + '0';
        }
        char full_number[MAX_N];
        for (int i = 0; i < n + 1; ++i) {
            full_number[i] = s[i] - '0';
        }
        // 计算余数
        int remainder = compute_remainder(full_number, n, x);
        if (remainder == y) {
            // 输出结果
            cout << s << endl;
            return;
        }

        // 更新try_number,除了第一位，其他的逢10进1，如果第一位加到10了，那么所有的尝试都结束了，循环也就该结束了
        try_number[unknown_number_index.size() - 1]++;
        for (int i = unknown_number_index.size() - 1; i >= 1; --i) {
            if (try_number[i] == 10) {
                try_number[i] = 0;
                try_number[i - 1]++;
            } else {
                if (dp[i - 1][remainder]) {
                    try_number[i] = 0;
                    try_number[i - 1]++;
                } else {
                    if (remainder != x) {
                        dp[i][remainder] = true;
                    }
                }
                remainder = x; // 将remainder余数设置为无效
            }
        }
    }
    cout << "No solution" << endl;
}

/**
 * 求余数
 */
int compute_remainder(char *s, int n, const int x) {
    int remainder[n];
    memset(remainder, 0, sizeof(int) * n);
    remainder[0] = ((int) s[0]) % x;
    for (int i = 1; i < n; ++i) {
        remainder[i] = (remainder[i - 1] * 10 + s[i]) % x;
    }
    return remainder[n - 1];
}

#endif //ALGORITHMS_OLD_NUMBER_H
