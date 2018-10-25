//
// Created by 袁浩 on 2018/10/25.
//

#ifndef ALGORITHMS_INCLUSION_EXCLUSION_PRINCIPLE_H

#include "../base/gcd.h"

/**
 * 求1到n的自然数中能被a中任意一个数整除的数的个数
 * @param n
 * @param a
 * @param len 数组a的长度
 * @return
 */
long long inclusion_exclusion_principle(long long n, long long *a, int len) {
    long long res = 0;
    for (int i = 1; i < (1 << len); ++i) {
        int num = 0;
        for (int j = i; j != 0; j >>= 1) {
            num += j & 1;
        }
        long long lcm = 1;
        for (int j = 0; j < len; ++j) {
            if (i >> j & 1) {
                lcm = lcm / gcd(lcm, a[j]) * a[j];
                if (lcm > n) {
                    break;
                }
            }
        }
        if (num % 2 == 0) {
            res -= n / lcm;
        } else {
            res += n / lcm;
        }
    }
    return res;
}

#define ALGORITHMS_INCLUSION_EXCLUSION_PRINCIPLE_H

#endif //ALGORITHMS_INCLUSION_EXCLUSION_PRINCIPLE_H
