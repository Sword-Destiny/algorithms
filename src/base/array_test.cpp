//
// Created by 袁浩 on 2018/10/31.
//

#include "../../include/mid_level/array.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    data_array<int> da(10);
    da[0] = 5;
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_array<int> da2(a, 10);
    cout << da2.index_of(da[0]) << endl;
    return 0;
}