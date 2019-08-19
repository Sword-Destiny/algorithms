//
// Created by yuanhao on 2019-8-15.
//
#include "../../include/hiho/old_number.h"

int main() {
    int x = 0, y = 0;
    char s[MAX_N];
    cin >> s;
    cin >> x;
    cin >> y;
    vector<int> unknowns;//未知数字
    int n = 0; // 数字长度
    for (int i = 0; i < MAX_N; ++i) {
        if (s[i] == '\0') {
            n = i;
            break;
        }
        if (s[i] == '?') {
            unknowns.push_back(i);
        }
    }
    old_number(s, unknowns, x, n, y);
}
