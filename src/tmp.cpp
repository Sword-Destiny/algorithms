#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int size = pow(2, n);
    int a[size];
    int i = 1;
    a[0] = -1;
    int len = 1;
    for (; i < n; i++) {
        a[len] = -1;
        for (int j = 1; j <= len; j++) {
            a[len + j] = -a[len - j];
        }
        len = len * 2 + 1;
    }
    for (int index = 0; index < len; index++) {
        if (a[index] == -1) {
            cout << "down" << endl;
        } else {
            cout << "up" << endl;
        }
    }
    return 0;
}