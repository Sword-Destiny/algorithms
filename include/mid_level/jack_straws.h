//
// Created by sworddestiny on 18-7-11.
//

#ifndef ALGORITHMS_JACK_STRAWS_H

#include "point.h"
#include <cstring>
#include <string>

using std::memset;
using std::string;

/**
 * 判断q是否在线段p1p2上
 * @param p1
 * @param p2
 * @param q
 * @return
 */
bool on_segment(Point p1, Point p2, Point q) {
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

/**
 * 求两条线段p1p2和q1q1交点
 * @param p1
 * @param p2
 * @param q1
 * @param q2
 * @return
 */
Point intersection(Point p1, Point p2, Point q1, Point q2) {
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

/**
 * 判断线段之间的连接关系
 * POJ 1127
 * @param n 线段数量
 * @param m 需要判断的对数
 * @param pq 线段
 * @param ab 需要判断的
 * @param result 判断结果
 */
void jack_straws(int n, int m, Point **pq, int **ab, string *result) {
    auto **g = new bool *[n];
    for (int i = 0; i < n; ++i) {
        g[i] = new bool[n];
        memset(g[i], 0, n * sizeof(*g[i]));
    }
    for (int i = 0; i < n; ++i) {
        g[i][i] = true;
        for (int j = 0; j < i; ++j) {
            if ((pq[i][0] - pq[i][1]).det(pq[j][0] - pq[j][1]) == 0) {
                //平行
                g[i][j] = g[j][i] =
                        on_segment(pq[i][0], pq[i][1], pq[j][0]) || on_segment(pq[i][0], pq[i][1], pq[j][1]) ||
                        on_segment(pq[j][0], pq[j][1], pq[i][0]) || on_segment(pq[j][0], pq[j][1], pq[i][1]);
            } else {
                Point r = intersection(pq[i][0], pq[i][1], pq[j][0], pq[j][1]);
                g[i][j] = g[j][i] = on_segment(pq[i][0], pq[i][1], r) && on_segment(pq[j][0], pq[j][1], r);
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        result[i] = g[ab[i][0]][ab[i][1]] ? "CONNECTED" : "NOT CONNECTED";
    }

    for (int i = 0; i < n; ++i) {
        delete[] g[i];
    }
    delete[] g;
}

#define ALGORITHMS_JACK_STRAWS_H

#endif //ALGORITHMS_JACK_STRAWS_H
