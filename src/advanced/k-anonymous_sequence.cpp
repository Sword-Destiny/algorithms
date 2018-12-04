//
// Created by 天命剑主 on 2018-12-4.
//

#include "../../include/advanced/k-anonymous_sequence.h"
#include <iostream>
#include "../../include/base/print_utilitys.h"

using std::cout;
using std::endl;

int main() {
    const int n = 7;
    const int k = 3;
    int a[n] = {2, 2, 3, 4, 4, 5, 5};
    cout << "a : ";
    print_array(cout, a, n);
    cout << endl;
    long long ans = k_anonymous_sequence(n, k, a);
    cout << "k_anonymous_sequence res : " << ans << endl;
    return 0;
}