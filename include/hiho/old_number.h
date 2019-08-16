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

using namespace std;
#define MAX_N 200

int divide_big_number(char *s, int n, int x);

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
 * @param s
 * @param unknown
 * @param x
 * @param y
 */
void old_number(char *s, vector<int> unknown, const int x, const int y) {
    int n = 0; // 数字长度
    for (int si = 0; si < MAX_N; ++si) {
        if (s[si] == '\0') {
            n = si;
            break;
        }
    }
    int try_number = 0;
    int try_max = pow(10, unknown.size());
    if (unknown[0] == 0 && n != 1) {
        try_number += pow(10, unknown.size() - 1);
    }
    for (; try_number < try_max; ++try_number) {
        string tmp_str = "";
        string try_str = to_string(try_number);
        for (int i = 0; i < unknown.size() - try_str.size(); ++i) {
            tmp_str.push_back('0');
        }
        tmp_str.append(try_str);
        for (int i = 0; i < unknown.size(); ++i) {
            s[unknown[i]] = tmp_str[i];
        }
        char try_s[MAX_N];
        for (int i = 0; i < n + 1; ++i) {
            try_s[i] = s[i] - '0';
        }
        if (divide_big_number(try_s, n, x) == y) {
            // 输出结果
            cout << s << endl;
            return;
        }
    }
    cout << "No solution" << endl;
}

/**
 * 大数减法,结果保留在s中
 * @param s
 * @param n
 * @param t
 * @param m
 * @return
 */
void subtract_big_number(char *s, int &n, char *t, int m) {
    int lend = 0; // 借位
    for (int si = n - 1; si >= 0; --si) {
        int ti = m - n + si;
        int number_t = ti < 0 ? 0 : t[ti];
        if (s[si] >= number_t + lend) {
            s[si] = s[si] - number_t - lend;
            lend = 0;
        } else {
            s[si] = s[si] + 10 - number_t - lend;
            lend = 1;
        }
    }

    // 如果前面减出来是0，那么结果要左移
    int shift_len = n;
    for (int si = 0; si < n; ++si) {
        if (s[si] != 0) {
            shift_len = si;
            break;
        }
    }
    for (int si = 0; si < n - shift_len; ++si) {
        s[si] = s[si + shift_len];
    }
    n -= shift_len;
    s[n] = '\0';
}

/**
 * 大数运算，大于等于判断
 * @param s
 * @param n
 * @param t
 * @param m
 * @return
 */
bool large_equal(char *s, int n, char *t, int m) {
    if (n > m) {
        return true;
    } else if (n < m) {
        return false;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] > t[i]) {
            return true;
        } else if (s[i] < t[i]) {
            return false;
        }
    }
    return true;
}

/**
 * 大数除法求余数
 * @param s
 * @param x
 * @return
 */
int divide_big_number(char *s, int n, const int x) {
    string tmp = to_string(x);
    int m = tmp.length();
    const char *st = tmp.c_str();
    char t[MAX_N];
    for (int i = 0; i < m; ++i) {
        t[i] = st[i] - '0';
    }
    t[m] = '\0';
    while (large_equal(s, n, t, m)) {
        if (n > m) {
            int d = n - m - 1;
            for (int i = 0; i < d; ++i) {
                t[m + i] = 0;
            }
            m += d;
            t[m] = '\0';
        } else {
            t[m] = '\0';
        }
        subtract_big_number(s, n, t, m);
        m = tmp.length();
        for (int i = 0; i < m; ++i) {
            t[i] = st[i] - '0';
        }
        t[m] = '\0';
    }
    for (int i = 0; i < n; ++i) {
        s[i] += '0';
    }
    return atoi(s);
}

#endif //ALGORITHMS_OLD_NUMBER_H
