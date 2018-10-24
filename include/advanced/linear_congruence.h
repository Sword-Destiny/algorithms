//
// Created by 袁浩 on 2018/10/24.
//

#ifndef ALGORITHMS_LINEAR_CONGRUENCE_H

#include "../base/gcd.h"
#include <utility>
#include <vector>

using std::vector;
using std::pair;
using std::make_pair;

/**
 * 求解线性同余方程组
 * a[i] * x ≡ b[i] (mod m[i])
 * 求x,可能无解,即返回(0,-1),有解即有无数解,返回一个数对(p,q),x≡p(mod q)
 *
 * @param A
 * @param B
 * @param M
 * @return
 */
pair<int, int> linear_congruence(const vector<int> &A, const vector<int> &B, const vector<int> &M) {
    int x = 0, m = 1;
    for (int i = 0; i < A.size(); ++i) {
        int a = A[i] * m, b = B[i] - A[i] * x, d = gcd(M[i], a);
        if (b % d != 0) {
            return make_pair(0, -1);
        }
        int t = b / d * mod_inverse(a / d, M[i] / d) % (M[i] / d);
        x = x + m * t;
        m *= M[i] / d;
    }
    return make_pair(x % m, m);
}

#define ALGORITHMS_LINEAR_CONGRUENCE_H

#endif //ALGORITHMS_LINEAR_CONGRUENCE_H
