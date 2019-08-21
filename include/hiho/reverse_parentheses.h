//
// Created by yuanhao on 2019-8-21.
//

#ifndef ALGORITHMS_REVERSE_PARENTHESES_H
#define ALGORITHMS_REVERSE_PARENTHESES_H

#include <string>
#include <iostream>
#include <algorithm>
#include <hash_map>

using namespace std;

#define N 5000010

// 这两个数据可能比较大，如果定义在函数内部可能会导致判题程序判断你内存超出。。。很蛋疼的问题，浪费了我一个下午时间
int p[N]; //计算括号对应的位置
string s; //字符串

void reverse(int &index);

void output(int begin, int end, bool reverse);

/**
 * 描述
 * 给定一个只包含括号和小写字母的字符串S，例如S="a(bc(de)fg)hijk"。
 * 其中括号表示将里面的字符串翻转。(注意括号可能嵌套)
 * 请你输出翻转之后的字符串。
 * 输入
 * 字符串S。
 * 对于50%的数据，|S| ≤ 1000
 * 对于100%的数据, |S| ≤ 5000000
 * 输出
 * 输出反转后的字符串(不带括号)。
 * 样例输入
 * a(bc(de)fg)hijk
 * 样例输出
 * agfdecbhijk
 */
void reverse_parentheses() {
    for (int i = 0; i < s.length(); ++i) {
        switch (s[i]) {
            case '(': {
                int sub_index = i + 1;
                reverse(sub_index);
                p[i] = sub_index;
                p[sub_index] = i;
                i = sub_index;
                break;
            }
            default: {
                p[i] = -1;
                break;
            }
        }
    }

    // 输出
    for (int i = 0; i < s.length(); ++i) {
        if (p[i] == -1) {
            cout << s[i];
        } else {
            output(i, p[i], true);
            i = p[i];
        }
    }
    cout << endl;
}

void reverse(int &index) {
    int i = index;
    for (; i < s.length();) {
        switch (s[i]) {
            case '(': {
                int sub_index = i + 1;
                reverse(sub_index);
                p[i] = sub_index;
                p[sub_index] = i;
                i = sub_index;
                break;
            }
            case ')': {
                goto end;
            }
            default: {
                p[i] = -1;
                break;
            }
        }
        i++;
    }

    end:
    index = i;
}

void output(int begin, int end, bool reverse) {
    if (!reverse) {
        for (int i = begin + 1; i < end; ++i) {
            if (p[i] == -1) {
                cout << s[i];
            } else {
                output(i, p[i], !reverse);
                i = p[i];
            }
        }
    } else {
        for (int i = end - 1; i > begin; --i) {
            if (p[i] == -1) {
                cout << s[i];
            } else {
                output(p[i], i, !reverse);
                i = p[i];
            }
        }
    }
}

#endif //ALGORITHMS_REVERSE_PARENTHESES_H
