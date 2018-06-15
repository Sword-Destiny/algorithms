//
// Created by yuanh on 2018/6/15.
//

#ifndef ALGORITHMS_SQRT_H

#include <cmath>

using std::abs;

#ifndef ACCURACY //精度
#define ACCURACY 0.000000001
#endif

/**
 * f = θ^2 - x
 * 令f = 0
 * 则θ = sqrt(x)
 * 可以用牛顿法逼近
 * θ[i+1] = θ[i] - f(θ[i])/f'(θ[i])
 * @param x 求x的平方根
 * @return x的平方根
 */
double sqrt_newton(double x) {
    if (x == 0) return 0;
    double theta = 0.0f;
    double theta2 = 1.0f;
    while (abs(theta2 - theta) > ACCURACY) {
        theta = theta2;
        theta2 = theta - (theta * theta - x) / (2.0f * theta);
    }
    return theta2;
}

float sqrt_newton(float x) {
    if (x == 0) return 0;
    float theta = 0.0f;
    float theta2 = 1.0f;
    while (abs(theta2 - theta) > ACCURACY) {
        theta = theta2;
        theta2 = theta - (theta * theta - x) / (2.0f * theta);
    }
    return theta2;
}

/**
 * 求x平方根
 * 这个无法检测小于0的非法情况,参数小于0会返回0
 * 约翰·卡马克
 * @param x 求x平方根
 * @return x平方根
 */
float sqrt_fast(float x) {
    if (x == 0) return 0;
    float result = x;
    float xhalf = 0.5f * result;
    unsigned int i = *(unsigned int *) &result;
    i = 0x5f375a86 - (i >> (unsigned)1);
    result = *(float *) &i;
    result = result * (1.5f - xhalf * result * result);
    result = result * (1.5f - xhalf * result * result);
    return 1.0f / result;
}

#define ALGORITHMS_SQRT_H

#endif //ALGORITHMS_SQRT_H
