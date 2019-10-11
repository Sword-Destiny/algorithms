//
// Created by yuanhao on 2019-10-11.
//

#include <iostream>
#include <cmath>

using namespace std;

//题目描述
//请把一张纸条竖着放在桌子上，然后从纸条的下边向上方对折1次，压出折痕后展开。此时折痕是凹下去的，即折痕突起的方向指向纸条的背面。如果从纸条的下边向上方连续对折2次，压出折痕后展开，此时有三条折痕，从上到下依次是下折痕、下折痕和上折痕。给定一个输入参数N，代表纸条都从下边向上方连续对折N次，请从上到下打印所有折痕的方向。
//输入描述:
//第一行一个整数N。表示对折次数
//输出描述:
//输出若干行，若该折痕向下，输出"down"，否则输出"up"
//示例1
//输入
//1
//输出
//down
int main() {
    int n;
    cin >> n;
    int size = pow(2, n);
    int a[size];
    int i = 1;
    a[0] = -1;
    int len = 1;
    for (; i < n; i++) {
        a[len] = -1;
        for (int j = 1; j <= len; j++) {
            a[len + j] = -a[len - j];
        }
        len = len * 2 + 1;
    }
    for (int index = 0; index < len; index++) {
        if (a[index] == -1) {
            cout << "down" << endl;
        } else {
            cout << "up" << endl;
        }
    }
    return 0;
}