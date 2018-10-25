//
// Created by 袁浩 on 2018/10/25.
//
#include <iostream>
using std::cout;
using std::endl;

#include "../../include/advanced/moebius.h"

int main(){
    int n = 2;
    int MOD = 10009;
    cout << n << "的莫比乌斯函数值为" << moebius(n,MOD) << endl << endl;

    n = 4;
    cout << n << "的莫比乌斯函数值为" << moebius(n,MOD) << endl << endl;

    n = 15315300;
    cout << n << "的莫比乌斯函数值为" << moebius(n,MOD) << endl << endl;
}