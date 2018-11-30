//
// Created by 天命剑主 on 2018-11-30.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/advanced/slice_min.h"
#include "../../include/base/print_utilitys.h"

int main() {
    const int n = 5;
    const int k = 3;
    int a[n] = {1, 3, 5, 4, 2};
    int indexs[k] = {-1, -1, -1};
    int res = slice_min(n, a, k, indexs);
    cout << "a : ";
    print_array(cout, a, n);
    cout << "\n" << endl;
    cout << "slice_min index : ";
    print_array(cout, indexs, k);
    cout << endl;
    cout << "slice_min res : " << res << endl;
    return 0;
}