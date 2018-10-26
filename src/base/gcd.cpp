//
// Created by 袁浩 on 2018/10/24.
//

#include <iostream>

using std::cout;
using std::endl;

#include "../../include/base/gcd.h"
#include "../../include/base/mod.h"

int main() {
    int a = 5;
    int m = 29;

    int x = mod_inverse(a, m);
    cout << "mod_inverse : " << a << "对" << m << "求逆元的结果是 : " << x << endl;

    cout << endl << "5的欧拉函数值为 : " << euler_phi(5) << endl;

    int n = 100;
    int euler[100];
    euler_phi2(n, euler);
    cout << endl << "埃氏筛法求欧拉函数值表 :" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << "->" <<euler[i] << ", ";
    }
    cout << endl;
}