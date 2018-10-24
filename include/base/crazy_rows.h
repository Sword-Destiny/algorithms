//
// Created by yuanh on 2018/5/28.
//

#ifndef ALGORITHMS_CRAZY_ROWS_H

#include <iostream>

using std::cout;
using std::endl;

#include <utility>

using std::swap;

/**
 * 要交换到第i行的最近行
 * @param list 每一行行最末尾1所在位置
 * @param n 行数
 * @param i i行
 * @return 要交换的最近行位置
 */
int min_index(const int *list, int n, int i) {
	for (int min_i = 0; min_i < n; ++min_i) {
		if (list[min_i] <= i) {
			return min_i;
		}
	}
	return 0;
}

/**
 * POJ 2009 Round2 A
 * 交换相邻行构成下三角矩阵
 * @param n 行数
 * @param m 矩阵
 * @return 最少交换次数
 */
int crazy_rows(int n, int **m) {
	int swap_num = 0;
	auto *last_none_zero = new int[n];
	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j >= 0; --j) {
			if (m[i][j] != 0) {
				last_none_zero[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int min_i = min_index(last_none_zero + i, n - i, i);
		if (min_i != 0) {
			int swap_index = min_i + i;
			for (int s = swap_index; s > i; --s) {
				// cout << "swap : " << (s - 1) << " <-> " << s << endl;//NOTE : comment
				swap_num++;
				swap(last_none_zero[s], last_none_zero[s - 1]);
				swap(m[s], m[s - 1]);
			}
		}
	}
	delete[] last_none_zero;
	return swap_num;
}

#define ALGORITHMS_CRAZY_ROWS_H

#endif //ALGORITHMS_CRAZY_ROWS_H
