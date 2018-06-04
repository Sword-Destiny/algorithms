//
// Created by yuanh on 2018/6/4.
//

#ifndef ALGORITHMS_FOUR_SUM_ZERO_H

#include <algorithm>

using std::sort;
using std::lower_bound;
using std::upper_bound;
using std::greater;
using std::less;

template<typename T>
struct _four_sum_zero_answer {
    T a, b, c, d;
};
template<typename T>
using four_sum_zero_answer = struct _four_sum_zero_answer<T>;

template<typename T>
struct _four_sum_zero_cd {
    T val;
    long index;
};
template<typename T>
using four_sum_zero_cd = struct _four_sum_zero_cd<T>;

template<typename T>
bool operator<(const four_sum_zero_cd<T> &cd1, const four_sum_zero_cd<T> &cd2) {
    return cd1.val < cd2.val;
}

template<typename T>
bool operator<(const four_sum_zero_cd<T> &cd1, const long int &cd2) {
    return cd1.val < cd2;
}

template<typename T>
bool operator<(const long int &cd1, const four_sum_zero_cd<T> &cd2) {
    return cd1 < cd2.val;
}

template<typename T>
/**
 * POJ No.2785
 * 4个数字和为0
 * @tparam T 类型参数
 * @param as a列表
 * @param bs b列表
 * @param cs c列表
 * @param ds d列表
 * @param n 列表长度n
 * @param answers 保存结果
 * @return 一共有多少组符合条件的
 */
long four_sum_zero(T *as, T *bs, T *cs, T *ds, long n, four_sum_zero_answer<T> *answers) {
    long N = n * n;
    auto *cd = new four_sum_zero_cd<T>[N];
    for (long ci = 0; ci < n; ++ci) {
        for (long di = 0; di < n; ++di) {
            cd[ci * n + di] = {cs[ci] + ds[di], ci * n + di};
        }
    }
    sort(cd, cd + N);
    long res = 0;
    for (long ai = 0; ai < n; ++ai) {
        for (long bi = 0; bi < n; ++bi) {
            long search = 0 - as[ai] - bs[bi];
            four_sum_zero_cd<T> *l = lower_bound(cd, cd + N, search);
            four_sum_zero_cd<T> *u = upper_bound(cd, cd + N, search);
            while (l != u) {
                long li = l->index;
                answers[res++] = {as[ai], bs[bi], cs[li / n], ds[li % n]};
                l++;
            }
        }
    }
    delete[] cd;
    return res;
}

#define ALGORITHMS_FOUR_SUM_ZERO_H

#endif //ALGORITHMS_FOUR_SUM_ZERO_H
