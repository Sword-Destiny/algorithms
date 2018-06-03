//
// Created by yuanh on 2018/5/26.
//

#include "../../include/base/prime.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    int n = 100;
    cout << "divisor " << n << " : " << endl;
    vector<int> res = divisor(n);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
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