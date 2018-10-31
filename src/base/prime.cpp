//
// Created by yuanh on 2018/5/26.
//

#include "../../include/base/prime.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 100;
    cout << "is_prime " << n << ": " << is_prime(n) << endl;
    cout << "divisor " << n << " : " << endl;
    vector<int> res = divisor(n);
    for (int re : res) {
        cout << re << " ";
    }
    cout << endl << endl << "factor " << n << " : " << endl;
    map<int, int> r = prime_factor(n);
    auto it = r.begin();
    while (it != r.end()) {
        cout << it->first << "^" << it->second << " ";
        it++;
    }
    cout << endl << endl;
    return 0;
}