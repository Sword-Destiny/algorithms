//
// Created by sworddestiny on 18-6-2.
//

#ifndef ALGORITHMS_FACE_THE_RIGHT_WAY_H

#include <cstring>

using std::memset;

enum face_direct {
	front = 0,
	back = 1,
};

inline bool is_back(int o) {
	return o % 2 != 0;
}

/**
 * 固定k进行求解
 * @param n 牛的数量
 * @param faces 牛的初始朝向
 * @param is_switch 是否翻转
 * @param k 每次翻转的最小长度
 * @return 所需要的最少翻转次数
 */
int fun_k(int k, int n, face_direct *faces, int *is_switch) {
	memset(is_switch, 0, n * sizeof(*is_switch));
	int res = 0;
	int sum = 0;//前面翻转的次数
	for (int i = 0; i <= n - k; ++i) {
		if (is_back(faces[i] + sum)) {
			res++;
			is_switch[i] = 1;
		}
		sum += is_switch[i];
		if (i - k + 1 >= 0) {
			sum -= is_switch[i - k + 1];
		}
	}
	// 检查最后的牛有没有不符合情况的
	for (int i = n - k + 1; i < n; ++i) {
		if (is_back(faces[i] + sum)) {
			return -1;
		}
		if (i - k + 1 >= 0) {
			sum -= is_switch[i - k + 1];
		}
	}
	return res;
}

/**
 * 队列翻转问题
 * POJ No.3276
 * @param n 牛的数量
 * @param faces 牛的初始朝向
 * @param is_switch 是否翻转
 * @param k 每次翻转的最小长度
 * @param m 所需要的最少翻转次数
 */
void face_the_right_way(int n, face_direct *faces, int *is_switch, int &k, int &m) {
	k = 1;
	m = n;
	for (int K = 1; K < n; ++K) {
		int M = fun_k(K, n, faces, is_switch);
		if (M >= 0 && M < m) {
			k = K;
			m = M;
		}
	}
	m = fun_k(k, n, faces, is_switch);
}

#define ALGORITHMS_FACE_THE_RIGHT_WAY_H

#endif //ALGORITHMS_FACE_THE_RIGHT_WAY_H
