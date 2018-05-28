//
// Created by yuanh on 2018/5/28.
//
#include "../include/crazy_rows.h"

int main() {
	int n = 4;
	auto **m = new int *[4]{
			new int[4]{1, 1, 1, 0},
			new int[4]{1, 1, 0, 0},
			new int[4]{1, 1, 0, 0},
			new int[4]{1, 0, 0, 0},
	};
	cout << "m :" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "crazy rows : " << crazy_rows(n, m) << endl << endl;
	cout << "m :" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}