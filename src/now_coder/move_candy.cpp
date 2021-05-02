//
// Created by yuanhao on 2020-1-7.
//
#include <iostream>
#include <cmath>

using namespace std;

//n 个小朋友坐在一排，每个小朋友拥有 ai 个糖果，现在你要在他们之间转移糖果，使得最后所有小朋友拥有的糖果数都相同，每一次，你只能从一个小朋友身上拿走恰好两个糖果到另一个小朋友上，问最少需要移动多少次可以平分糖果，如果方案不存在输出 -1。
//
//
//输入描述:
//每个输入包含一个测试用例。每个测试用例的第一行包含一个整数n（1 <= n <= 100），接下来的一行包含n个整数ai（1 <= ai <= 100）。
//
//
//输出描述:
//输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出-1。
//示例1
//输入
//4
//7 15 9 5
//输出
//3
int main() {
    int n = 0;
    cin >> n;
    int *candy = new int[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> candy[i];
        sum += candy[i];
    }
    if (sum % n != 0) {
        cout << -1 << endl;
        delete[] candy;
        return 0;
    }
    int average = sum / n;

    int times = 0;
    for (int i = 0; i < n; ++i) {
        int d = abs(candy[i] - average);
        if (d % 2 != 0) {
            cout << -1 << endl;
            delete[] candy;
            return 0;
        }
        times += d / 2;
    }

    cout << times / 2 << endl;
    delete[] candy;
    return 0;
}