//
// Created by yuanhao on 2020-1-7.
//
#include <iostream>
#include <cstring>

using namespace std;

int getcount(int num) {
    int count = 0;
    int i = 0;
    while (num) {
        num = num & (num - 1);
        count++;
    }
    return count;
}

void one() {
    int n;
    cin >> n;
    int counts[32];
    memset(counts, 0, 32 * sizeof(int));
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int count = getcount(num);
        counts[count]++;
    }
    int sum = 0;
    for (int i = 0; i < 32; i++) {
        if (counts[i] > 0) {
            sum++;
        }
    }
    cout << sum << endl;
}

//小A刚学了二进制，他十分激动。为了确定他的确掌握了二进制，你给他出了这样一道题目：给定N个非负整数，将这N个数字按照二进制下1的个数分类，二进制下1的个数相同的数字属于同一类。求最后一共有几类数字？
//
//
//输入描述:
//输入的第一行是一个正整数T（0<T<=10），表示样例个数。对于每一个样例，第一行是一个正整数N（0<N<=100），表示有多少个数字。接下来一行是N个由空格分隔的非负整数，大小不超过2^31 – 1。，
//
//
//输出描述:
//对于每一组样例，输出一个正整数，表示输入的数字一共有几类。
//示例1
//输入
//1
//5
//8 3 5 7 2
//输出
//3
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        one();
    }
}