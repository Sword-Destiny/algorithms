//
// Created by yuanhao on 2020-1-8.
//
#include "../../include/base/longest_increasing_subsequence.h"
#include <iostream>
#include <string>

using namespace std;

//输入一个数组，输出最长升序子序列的长度。
//
//输入描述:
//一组数组，长度不大于10^510
//5
//
//
//
//输出描述:
//一个整数，最长升序子序列的长度
//示例1
//输入
//5,1,4,2,3
//输出
//3
//说明
//最长升序子序列为1,2,3，长度为3
int main() {
    int sequence[100000];
    int len = 0;
    string s;
    getline(cin, s); // 此题输入不规范，有些用例有空格，有些输入没有空格
    size_t pos = -1; // size_t是非负类型，这里的-1并不是-1，但是pos+1之后溢出，仍然是0
    do {
        sequence[len++] = (int) strtol(s.c_str() + pos + 1, nullptr, 10);
    } while ((pos = s.find(',', pos + 1)) != string::npos);
    int ans = longest_increasing_subsequence_efficient(sequence, len);
    cout << ans << endl;
}