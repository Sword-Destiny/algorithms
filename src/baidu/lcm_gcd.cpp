//
// Created by yuanhao on 2019-9-24.
//

#include <iostream>
#include <cmath>

using namespace std;

/**
 * 输入n，找到两个数a,b
 * 1<=a,b<=n
 * 使lsm(a,b)-gcd(a,b)最大，其中lsm是最小公倍数，gcd是最大公约数
 * 输出lsm(a,b)-gcd(a,b)
 * @return
 */
int main() {
    long long n;
    cin >> n;
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3) {
        cout << 5 << endl;
        return 0;
    }
    cout << ((n - 1) * n - 1) << endl;
    return 0;
}