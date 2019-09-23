//
// Created by yuanhao on 2019-9-16.
//

#include <iostream>

using namespace std;

//输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
//
//输入描述:
//输入包含三行，
//
//第一行包含两个正整数n, m（1 ≤ n,m ≤ 100），用空格分隔。n表示第二行第一个升序序列中数字的个数，m表示第三行第二个升序序列中数字的个数。
//
//第二行包含n个整数（范围1~5000），用空格分隔。
//
//第三行包含m个整数（范围1~5000），用空格分隔。
//
//
//输出描述:
//输出为一行，输出长度为n+m的升序序列，即长度为n的升序序列和长度为m的升序序列中的元素重新进行升序序列排列合并。
//示例1
//输入
//5 6
//1 3 7 9 22
//2 8 10 17 33 44
//输出
//1 2 3 7 8 9 10 17 22 33 44
int main() {
    int n;
    int m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int len = n + m;
    int index = 0;
    int ai = 0;
    int bi = 0;
    while (index < len) {
        if (ai == n) {
            cout << b[bi] << " ";
            bi++;
        } else if (bi == m) {
            cout << a[ai] << " ";
            ai++;
        } else if (a[ai] > b[bi]) {
            cout << b[bi] << " ";
            bi++;
        } else {
            cout << a[ai] << " ";
            ai++;
        }
        index++;
    }
    cout << endl;
    return 0;
}