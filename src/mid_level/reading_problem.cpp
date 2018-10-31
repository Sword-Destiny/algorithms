//
// Created by yuanh on 2018/6/1.
//
#include "../../include/mid_level/reading_problem.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int page = 10;
    int a[10] = {5, 1, 3, 5, 5, 1, 4, 4, 3, 1};
    int begin = 0, end = 0;
    int res = reading_problem(page, a, begin, end);
    cout << "reading problem res : " << res << endl;
    cout << "begin : " << begin << endl;
    cout << "end : " << end << endl;
    return 0;
}
