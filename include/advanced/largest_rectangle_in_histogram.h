//
// Created by 天命剑主 on 2018-11-27.
//

#ifndef ALGORITHMS_LARGEST_RECTANGLE_IN_HISTOGRAM_H
#define ALGORITHMS_LARGEST_RECTANGLE_IN_HISTOGRAM_H

#include <algorithm>

using std::max;

#include <stack>

using std::stack;

/**
 * 有n个宽度为1，高度为h1到hn的长方形从左到右排列在一起形成柱状图，
 * 问里面包含的长方形的最大面积是多少
 * @param n 长方形数量
 * @param heights 长方形高度
 * @return 最大面积
 */
long long largest_rectangle_in_histogram(int n, const int *heights) {
    int *left = new int[n];
    int *right = new int[n];
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    s = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, (long long) heights[i] * (right[i] - left[i]));
    }
    delete[](left);
    delete[](right);
    return res;
}

#endif //ALGORITHMS_LARGEST_RECTANGLE_IN_HISTOGRAM_H
