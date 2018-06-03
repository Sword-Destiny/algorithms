//
// Created by sworddestiny on 18-5-22.
//

#include "../../include/base/binaty_color_graph.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	int n = 10;
	auto *colors = new int[n];
	for (int i = 0; i < n; ++i) {
		colors[i] = 0;
	}
	auto G = new int *[n];
	for (int i = 0; i < n; ++i) {
		G[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			G[i][j] = 0;
		}
	}
	G[1][2] = 1;
	G[2][3] = 1;
	//G[2][4] = 1;//false
	G[3][4] = 1;
	//G[6][3] = 1;//false
	G[5][6] = 1;
	G[7][5] = 1;
	G[9][7] = 1;
	G[8][9] = 1;
	G[0][8] = 1;
	G[0][1] = 1;
	G[2][8] = 1;
	cout << "binary color graph : " << (binary_color_graph(G, n, colors) ? "true" : "false") << endl; // true
	cout << "colors: ";
	for (int i = 0; i < n; ++i) {
		cout << colors[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		delete[] G[i];
	}
	delete[] G;
	delete[] colors;
	return 0;
}