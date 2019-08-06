//
// Created by yuanhao on 2019-8-6.
//

#ifndef ALGORITHMS_EXCHANGE_LARGEST_NUMBER_H
#define ALGORITHMS_EXCHANGE_LARGEST_NUMBER_H

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 给定一个整数N，你需要交换两个不同位置上的数字。请问能得到的最大整数是多少？
 * 注意：你可以把数字0交换到首位，输出时保留前导0。
 * 输入
 * 一个整数N (10 <= N <= 10^100000)
 * 输出
 * 一个整数代表答案
 * 样例输入
 * 123
 * 样例输出
 * 321
 */
// 基本思想是将最后最大的数字交换到前面来，考虑时间复杂度所以必须使用排序而不能直接遍历所有交换可能
string exchange_largest_number(const string &number) {
    string input = number;//复制输入

    char *s = (char *) number.c_str();
    std::sort(s, s + number.length(), std::greater<char>());//对字符倒序排序

    int swapi, swapj; // 交换位置
    for (int i = 0; i < number.length(); ++i) {
        if (s[i] > input[i]) {
            swapi = i;
            swapj = number.length() - 1;
            for (; swapj >= 0; swapj--) {
                if (input[swapj] == s[i]) {
                    break;
                }
            }
            //交换
            char tmp = input[swapi];
            input[swapi] = input[swapj];
            input[swapj] = tmp;
            return input;
        }
    }
    //如果输入数据严格倒序，若有重复数字，则交换这两个数字之后，大小不变
    for (int i = 0; i < number.length() - 1; ++i) {
        int j = i + 1;
        if(input[i] == input[j]){
            return input;
        }
    }
    //若没有重复数字，交换最后两个最小的数字
    swapi = number.length() - 1;
    swapj = number.length() - 2;
    char tmp = input[swapi];
    input[swapi] = input[swapj];
    input[swapj] = tmp;
    return input;
}

#endif //ALGORITHMS_EXCHANGE_LARGEST_NUMBER_H
