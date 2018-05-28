//
// Created by yuanh on 2018/5/28.
//

#ifndef ALGORITHMS_MINIMUM_SCALAR_PRODUCT_H

#include <algorithm>
#include <functional>

using std::sort;
using std::greater;
using std::less;

template<typename T>
/**
 * 求向量内积最小值
 * @tparam T 模板参数
 * @param v1 向量1
 * @param v2 向量2
 * @param n 向量长度
 * @return 最小内积
 */
T minimum_scalar_product(T *v1, T *v2, int n) {
    T res = 0;
    sort(v1, v1 + n);
    sort(v2, v2 + n, greater<T>());
    for (int i = 0; i < n; ++i) {
        res += v1[i] * v2[i];
    }
    return res;
}

#define ALGORITHMS_MINIMUM_SCALAR_PRODUCT_H

#endif //ALGORITHMS_MINIMUM_SCALAR_PRODUCT_H
