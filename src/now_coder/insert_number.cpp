//
// Created by yuanhao on 2019-10-6.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    bool output = false;

    for (int i = 0; i < n; i++) {
        if (a[i] > m && !output) {
            cout << m << " ";
            output = true;
        }
        cout << a[i] << " ";
    }
    if (!output) {
        cout << m << " ";
    }
    return 0;
}