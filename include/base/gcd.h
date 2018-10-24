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
T extgcd(T a, T b, T &x, T &y) {
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

int mod_inverse(int a, int m) {
    int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

#define ALGORITHMS_GCD_H

#endif //ALGORITHMS_GCD_H
