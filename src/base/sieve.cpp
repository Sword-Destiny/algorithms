//
// Created by yuanh on 2018/5/27.
//
#include "../../include/base/sieve.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 97;
    auto *prime = new int[n / 2 + 1];
    int prime_num = sieve(prime, n);
    cout << "prime <= " << n << " : ";
    for (int i = 0; i < prime_num; ++i) {
        cout << prime[i] << " ";
    }
    cout << endl;
    delete[] prime;
    return 0;
}
