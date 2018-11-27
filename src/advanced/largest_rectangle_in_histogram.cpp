//
// Created by 天命剑主 on 2018-11-27.
//

#include "../../include/advanced/largest_rectangle_in_histogram.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 7;
    int heights[7] = {2, 1, 4, 5, 1, 3, 3};
    long long res = largest_rectangle_in_histogram(n, heights);
    cout << "largest_rectangle_in_histogram res : " << res << endl;
    return 0;
}