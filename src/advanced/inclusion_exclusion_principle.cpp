//
// Created by 袁浩 on 2018/10/25.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/advanced/inclusion_exclusion_principle.h"
#include "../../include/base/print_utilitys.h"

int main() {
    long long n = 100;
    long long a[3] = {2, 3, 7};
    int len = 3;
    long long res = inclusion_exclusion_principle(n, a, len);
    cout << "在1到" << n << "中, \n能被(";
    print_array(cout, a, len);
    cout << ")中任意一个数整除的数，" << endl << "一共有 " << res << " 个。" << endl;

    cout << endl;

    n = 200;
    len = 4;
    long long b[4] = {2, 3, 5, 7};
    res = inclusion_exclusion_principle(n, b, len);
    cout << "在1到" << n << "中, \n能被(";
    print_array(cout, b, len);
    cout << ")中任意一个数整除的数，" << endl << "一共有 " << res << " 个。" << endl;
}