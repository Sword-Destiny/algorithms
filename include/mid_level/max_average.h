//
// Created by yuanh on 2018/5/30.
//

#ifndef ALGORITHMS_MAX_AVERAGE_H

#include <algorithm>
#include <functional>

using std::sort;
using std::greater;

typedef struct _max_average_s {
    double v; // value
    double w; // weight
    double y; // y = v - x * w;
} max_average_s;

bool operator<(const max_average_s &a1, const max_average_s &a2) {
    return a1.y < a2.y;
}

bool operator>(const max_average_s &a1, const max_average_s &a2) {
    return a1.y > a2.y;
}

bool fit(int k, int n, const double *v, const double *w, double x, double *y) {
    for (int i = 0; i < n; ++i) {
        y[i] = v[i] - x * w[i];
    }
    sort(y, y + n, greater<double>());
    double sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += y[i];
    }
    return sum >= 0;
}

/**
 * max average
 * 有n个物品的种类和价值分别为wi和vi,从中选出个物品使得平均单位价值最高
 * 注意此题受到精度影响
 * @param k 选出k个
 * @param n 物品数量
 * @param v 物品价值
 * @param w 物品重量
 * @param res 保存选择结果
 * @return 最高平均单位价值
 */
double max_average(int k, int n, const double *v, const double *w, max_average_s *res) {
    double accuracy = 0.0001; //精度
    auto *y = new double[n];
    double lb = 0;
    double ub = 0;
    for (int i = 0; i < n; ++i) {
        double x = v[i] / w[i];
        if (x > ub) {
            ub = x;
        }
    }
    while (ub - lb > accuracy) {
        double mid = (ub + lb) / 2;
        if (fit(k, n, v, w, mid, y)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    for (int i = 0; i < n; ++i) {
        res[i].v = v[i];
        res[i].w = w[i];
        res[i].y = v[i] - lb * w[i];
    }
    sort(res, res + n, greater<max_average_s>());
    double sum_v = 0, sum_w = 0;
    for (int i = 0; i < k; ++i) {
        sum_v += res[i].v;
        sum_w += res[i].w;
    }
    delete[] y;
    return sum_v / sum_w;
}

#define ALGORITHMS_MAX_AVERAGE_H

#endif //ALGORITHMS_MAX_AVERAGE_H
