//
// Created by sworddestiny on 17-12-18.
//

#include <iostream>
#include "include/longest_increasing_subsequence.h"

using std::cout;
using std::endl;

int main() {
    int a[10] = {1, 43, 2, 23, 23, 2, 53, 4, 53, 8};
    int n = 10;
    cout << "seq : ";
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << endl;
    int result = longest_increasing_subsequence_efficient(a, n);
    cout << "longest increasing subsequence: " << result << endl;
    return 0;
}