//
// Created by yuanh on 2018/6/1.
//

#ifndef ALGORITHMS_READING_PROBLEM_H

#include <set>

using std::set;

#include <map>

using std::map;

/**
 * POJ No.3320
 * 找知识点问题,找出包含所有知识点的最小区间页数
 * 注意结果区间[begin,end)是左闭右开的
 * @param page 总页数
 * @param a 每页知识点
 * @param begin 保存结果区间
 * @param end 保存结果区间
 * @return 结果区间长度
 */
int reading_problem(int page, int *a, int &begin, int &end) {
    // 找出所有知识点
    set<int> all;
    for (int i = 0; i < page; ++i) {
        all.insert(a[i]);
    }
    long n = all.size();
    // 尺取法
    int b = 0;
    int e = 0;
    int num = 0;
    map<int, int> count;
    int res = page + 1;
    while (true) {
        while (e < page && num < n) {
            if (count[a[e++]]++ == 0) {
                num++;
            }
        }
        if (num < n) {
            break;
        }
        if (res > e - b) {
            begin = b;
            end = e;
            res = e - b;
        }
        if (--count[a[b++]] == 0) {
            num--;
        }
    }
    return res;

}

#define ALGORITHMS_READING_PROBLEM_H

#endif //ALGORITHMS_READING_PROBLEM_H
