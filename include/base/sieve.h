//
// Created by yuanh on 2018/5/27.
//

#ifndef ALGORITHMS_SIEVE_H

/**
 * 埃氏筛法求<=N素数
 * @param prime 保存求到的素数
 * @param n N
 * @return <=N的素数个数
 */
int sieve(int *prime, int n) {
    auto *is_prime = new int[n + 1];
    int prime_num = 0;
    for (int i = 2; i <= n; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime[prime_num++] = i;
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    delete[] is_prime;
    return prime_num;
}

#define ALGORITHMS_SIEVE_H

#endif //ALGORITHMS_SIEVE_H
