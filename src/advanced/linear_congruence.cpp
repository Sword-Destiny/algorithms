//
// Created by 袁浩 on 2018/10/24.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/advanced/linear_congruence.h"

int main() {
    vector<int> a, b, m;
    a.emplace_back(5);
    a.emplace_back(6);
    b.emplace_back(1);
    b.emplace_back(2);
    m.emplace_back(29);
    m.emplace_back(17);

    pair<int, int> res = linear_congruence(a, b, m);

    cout << "线性同余方程组: a[i] * x ≡ b[i] (mod m[i])" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << a[i] << "\t* x ≡ " << b[i] << "\t(mod " << m[i] << "\t)" << endl;
    }
    cout << endl << "linear_congruence res :\nx ≡ " << res.first << " (mod " << res.second << ")" << endl; // 6,29
}