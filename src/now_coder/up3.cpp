//
// Created by yuanhao on 2019-9-4.
//

#include <iostream>

int v[100001];
int n;
using namespace std;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int max = 0;
    int min = 0;
    bool first = false;
    for (int i = 0; i < n - 1; i++) {
        if (first) {
            if (v[i] > min && v[i] < max) {
                max = v[i];
            }
            if (v[i] > max) {
                cout << "true" << endl;
                return 0;
            }
        }
        if (v[i] < v[i + 1]) {
            if (!first) {
                max = v[i + 1];
                min = v[i];
                first = true;
            } else {
                if (v[i + 1] < max) {
                    max = v[i + 1];
                    if (v[i] < min) {
                        min = v[i];
                    }
                }
            }
        }
    }
    if (max < v[n - 1]&&first) {
        cout << "true" << endl;
        return 0;
    }
    cout << "false" << endl;
    return 0;
}
