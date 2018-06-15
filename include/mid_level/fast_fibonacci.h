//
// Created by yuanh on 2018/6/6.
//

#ifndef ALGORITHMS_FAST_FIBONACCI_H

#include "matrix.h"

template<typename T>
T fast_fibonacci(unsigned int n, T mod) {
    matrix<T> m(2, 2);
    m[0][0] = 1;
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 0;
    m = m.pow(n, mod);
    return m[1][0];
}

#define ALGORITHMS_FAST_FIBONACCI_H

#endif //ALGORITHMS_FAST_FIBONACCI_H
