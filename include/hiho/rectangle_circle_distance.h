//
// Created by yuanhao on 2019-8-19.
//

#ifndef ALGORITHMS_RECTANGLE_CIRCLE_DISTANCE_H
#define ALGORITHMS_RECTANGLE_CIRCLE_DISTANCE_H

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point first;
    point second;
} line;

inline double distance(point p, point q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

/**
 * 描述
 * 在2D平面上给定一个矩形(边平行于坐标轴)和一个圆，我们规定矩形和圆的距离如下：
 * 从矩形内(包含边上)任取一点P、从圆内(包含圆周上)任取一点Q，所有可能的PQ两点之间距离的最小值。
 * 请你计算矩形和圆的距离。
 * 输入
 * 输入包含多组数据
 * 第一行包含一个整数T，代表数据组数。
 * 每组数据的第一行包含4个整数X1, Y1, X2, Y2。其中(X1, Y1)是矩形左下角的坐标，(X2, Y2)是矩形右上角的坐标。
 * 每组数据的第二行包含3个整数X3, Y3, R。其中(X3, Y3)是圆心坐标，R是圆的半径。
 * 输出
 * 对于每组数据输出一个数代表答案。
 * 只要你的答案误差不超过0.01就算正确。
 * 样例输入
 * 2
 * 0 0 1 1
 * 1 1 1
 * 0 0 2 2
 * 4 1 1
 * 样例输出
 * 0.000000
 * 1.000000
 */
double rectangle_circle_distance(point left_down, point right_top, point circle, int r) {
    // 圆心在方形内部
    if (circle.x <= right_top.x && circle.x >= left_down.x && circle.y <= right_top.y &&
        circle.y >= left_down.y) {
        return 0.0;
    }

    point left_top = {left_down.x, right_top.y};
    point right_down = {right_top.x, left_down.y};
    //横线
    line l1 = {left_down, right_down};
    line l2 = {left_top, right_top};
    //竖线
    line l3 = {right_down, right_top};
    line l4 = {left_down, left_top};
    //四点和圆的距离
    double d1 = distance(left_top, circle) - r;
    double d2 = distance(left_down, circle) - r;
    double d3 = distance(right_down, circle) - r;
    double d4 = distance(right_top, circle) - r;
    double res = min(d1, min(d2, min(d3, d4)));

    if (l1.first.x <= circle.x && l1.second.x >= circle.x) {
        double dl1 = abs(l1.first.y - circle.y) - r;
        double dl2 = abs(l2.first.y - circle.y) - r;
        res = min(res, min(dl1, dl2));
    }

    if (l3.first.y <= circle.y && l3.second.y >= circle.y) {
        double dl3 = abs(l3.first.x - circle.x) - r;
        double dl4 = abs(l4.first.x - circle.x) - r;
        res = min(res, min(dl3, dl4));
    }

    return max(res, 0.0); // 如果小于0那是相交了
}

#endif //ALGORITHMS_RECTANGLE_CIRCLE_DISTANCE_H
