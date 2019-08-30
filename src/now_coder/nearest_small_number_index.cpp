//
// Created by yuanhao on 2019-8-30.
//

#include <iostream>

using namespace std;

//给定一个可能含有重复值的数组 arr，找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置。返回所有位置相应的信息。
//
//输入描述:
//第一行输入一个数字 n，表示数组 arr 的长度。
//以下一行输入 n 个数字，表示数组的值
//
//
//输出描述:
//输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
//示例1
//输入
//7
//3 4 1 5 6 2 7
//输出
//-1 2
//0 2
//-1 -1
//2 5
//3 5
//2 -1
//5 -1
int main() {
    int n = 0;
    cin >> n;
    int numbers[n];
    int l_res[n];
    int r_res[n];
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    int stack[n]; // 栈，保存下标
    int top = 0; //栈顶指针
    for (int i = 0; i < n; ++i) {
        while (top != 0 && numbers[i] < numbers[stack[top - 1]]) {
            r_res[stack[top - 1]] = i;
            top --;
        }
        if (top == 0) {
            l_res[i] = -1;
        } else {
            if (numbers[i] == numbers[stack[top - 1]]) {
                l_res[i] = l_res[stack[top - 1]];
            } else {
                l_res[i] = stack[top - 1];
            }
        }
        stack[top++] = i;
    }
    while (top != 0) {
        r_res[stack[top - 1]] = -1;
        top --;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", l_res[i], r_res[i]);
    }

    return 0;
}