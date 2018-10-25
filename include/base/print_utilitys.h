//
// Created by 袁浩 on 2018/10/25.
//

#ifndef ALGORITHMS_PRINT_UTILITYS_H

#include <iostream>

using std::ostream;

template<typename T, typename L>
/**
 * 输出数组
 * @tparam T
 * @tparam L
 * @param o
 * @param array 数组
 * @param len 数组长度
 */
void print_array(ostream &o, T *array, L len) {
    if (len > 0) {
        for (L i = 0; i < len - 1; ++i) {
            o << array[i] << ", ";
        }
        o << array[len - 1];
    }
}

#define ALGORITHMS_PRINT_UTILITYS_H

#endif //ALGORITHMS_PRINT_UTILITYS_H
