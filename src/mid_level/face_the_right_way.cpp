//
// Created by sworddestiny on 18-6-2.
//
#include "../../include/mid_level/face_the_right_way.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	int n = 7;
	face_direct faces[7] = {back, back, front, back, front, back, back};
	int m = n;
	int k = 1;
	auto *is_switch = new int[n];
	face_the_right_way(n, faces, is_switch, k, m);
	cout << "face_the_right_way:" << endl;
	cout << "k : " << k << endl;
	cout << "row : " << m << endl;
	cout << "is_switch : ";
	for (int i = 0; i < n; ++i) {
		cout << is_switch[i] << " ";
	}
	cout << endl;
	delete[] is_switch;
	return 0;
}
