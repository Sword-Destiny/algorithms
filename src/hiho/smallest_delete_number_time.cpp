//
// Created by yuanhao on 2019-8-19.
//

#include "../../include/hiho/smallest_delete_number_time.h"

int main() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    cout << smallest_delete_number_time(numbers, n) << endl;
    return 0;
}