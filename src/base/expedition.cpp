//
// Created by sworddestiny on 17-12-23.
//

#include "../../include/base/expedition.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	int np1 = 5, L = 25, init_tank = 10;
	auto *stops = new expedition_stop[5]{{10, 10},
										 {14, 5},
										 {20, 2},
										 {21, 4},};
	int answer = expedition(stops, np1, L, init_tank);
	cout << "answer: " << answer << " should be 2." << endl;
	delete[] stops;
	return 0;
}
