//
// Created by yuanh on 2018/5/28.
//
#include "../../include/base/crazy_rows.h"

int main() {
	int n = 4;
	auto **m = new int *[4]{
			new int[4]{1, 1, 1, 0},
			new int[4]{1, 1, 0, 0},
			new int[4]{1, 1, 0, 0},
			new int[4]{1, 0, 0, 0},
	};
	cout << "row :" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int sn = crazy_rows(n, m);
	cout << "crazy rows : " << sn << endl << endl;
	cout << "row :" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		delete[] m[i];
	}
	delete[] m;
	return 0;
}