//
// Created by yuanhao on 2019-10-8.
//

#include <algorithm>
#include <iostream>

using namespace std;

//给定一个数组arr，请将数组调整为依次相邻的数字，总是先<=、再>=的关系，并交替下去。比如数组中有五个数字，调整成[a,b,c,d,e],使之满足a<=b>=c<=d>=e。
//
//输入描述:
//输入包含两行，第一行一个整数n（1 \leq n \leq 10^5）（1≤n≤10
//5
// ），代表数组的长度,接下来一行n个整数，代表数组arr（1 \leq arr_i \leq 10^9）（1≤arr
//i
//​
// ≤10
//9
// ）。
//
//
//输出描述:
//输出一行，代表调整后的数组。
//示例1
//输入
//6
//1 2 3 4 5 6
//输出
//1 3 2 5 4 6
int main() {
    int n;
    cin >> n;
    int right = n / 2;
    int left = n - right;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < right; ++i) {
        cout << arr[i] << " " << arr[left + i] << " ";
    }
    if (left != right) {
        cout << arr[left - 1];
    }
    return 0;
}