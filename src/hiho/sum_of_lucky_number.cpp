//
// Created by yuanhao on 2019-9-23.
//
#include <iostream>
#include <string>

using namespace std;

void mul_2(int *a, int n) {
    int carry = 0;
    for (int i = n - 1; i >= 0; --i) {
        a[i] = a[i] * 2 + carry;
        if (a[i] > 9) {
            a[i] -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
}

//描述
//如果一个十进制数只包含数字0和1，我们就称它是"幸运数"。例如0、1、10、11、100、1110等都是幸运数。
//
//给定一个整数N，请你计算N一共有多少种方法表示成两个非负幸运数的和。注意交换两个数的顺序视为同一种方法。
//
//输入
//一个整数N。
//
//0 <= N <= 10^100
//
//输出
//一个整数表示答案
//
//样例输入
//101
//样例输出
//2
int main() {
    string str;
    cin >> str;
    long long one_count = 0;
    for (char i : str) {
        if (i == '1') {
            one_count++;
        } else if (i == '0' || i == '2') {
            continue;
        } else {
            cout << "0" << endl;
            return 0;
        }
    }
    if (one_count == 0) {
        cout << 1 << endl;
        return 0;
    }
    // 超出long long能表示的范围，所以要用大数乘法计算pow(2,one_count-1)的值
    int a[100];
    for (int i = 0; i < 99; ++i) {
        a[i] = 0;
    }
    a[99] = 1;
    for (long long i = 0; i < one_count - 1; ++i) {
        mul_2(a, 100);
    }
    int index = 0;
    for (int i = 0; i < 100; ++i) {
        if (a[i] != 0) {
            index = i;
            break;
        }
    }
    for (int i = index; i < 100; ++i) {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
