//
// Created by yuanh on 2018/6/5.
//
#include "../../include/mid_level/bubble_swap_times.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 4;
    int arr[4] = {3, 1, 4, 2};
    long long answer = bubble_swap_times(n, arr);
    cout << "arr : ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "bubble_swap_times : " << answer << endl;
    return 0;
}
