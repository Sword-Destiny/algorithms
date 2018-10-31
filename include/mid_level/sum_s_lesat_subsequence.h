//
// Created by yuanh on 2018/5/31.
//

#ifndef ALGORITHMS_SUM_S_LESAT_SUBSEQUENCE_H

/**
 * POJ No.3061
 * 求总和不小于s的连续子序列长度最小值
 * 注意结果区间[begin,end)是左闭右开的
 * @param a 序列
 * @param n 序列总长度
 * @param s 总和s
 * @param begin 保存结果区间
 * @param end 保存结果区间
 * @return 结果区间长度,如果res>n则为无解
 */
int sum_s_lesat_subsequence(const int *a, int n, int s, int &begin, int &end) {
    int res = n + 1;
    int b = 0;
    int e = 0;
    begin = 0;
    end = 0;
    int sum = 0;
    while (true) {
        while (e < n && sum < s) {
            sum += a[e++];
        }
        if (sum < s) {
            break;
        }
        if (res > e - b) {
            begin = b;
            end = e;
            res = e - b;
        }
        sum -= a[b++];
    }
    if (res > n) {
        res = 0;
    }
    return res;
}

#define ALGORITHMS_SUM_S_LESAT_SUBSEQUENCE_H

#endif //ALGORITHMS_SUM_S_LESAT_SUBSEQUENCE_H
