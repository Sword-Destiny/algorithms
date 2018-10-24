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

// 求欧拉函数值O(√n)
int euler_phi(int n) {
    int res = n;
    for (int i = 2; i * i < n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            for (; n % i == 0; n /= i);
        }
    }
    if (n != 1) {
        res = res / n * (n - 1);
    }
    return res;
}

// 用埃氏筛法在O(n)的时间内筛选出欧拉函数值表
void euler_phi2(int n, int *euler) {
    for (int i = 0; i < n; ++i) {
        euler[i] = i;
    }
    for (int i = 2; i < n; ++i) {
        if (euler[i] == i) {
            for (int j = i; j < n; j += i) {
                euler[j] = euler[j] / i * (i - 1);
            }
        }
    }
}

#define ALGORITHMS_GCD_H

#endif //ALGORITHMS_GCD_H
