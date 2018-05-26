//
// Created by yuanh on 2018/5/26.
//

#ifndef ALGORITHMS_GCD_H

template<typename T>
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

template<typename T>
T extgcd(int a, int b, int &x, int &y) {
    T d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

#define ALGORITHMS_GCD_H

#endif //ALGORITHMS_GCD_H
