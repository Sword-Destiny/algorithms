//
// Created by yuanhao on 2019-8-16.
//
#include "../../include/hiho/max_multiply.h"

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num = 0;
        vector<long long> numbers;
        long long number = 0;
        cin >> num;
        for (int ni = 0; ni < num; ++ni) {
            cin >> number;
            numbers.push_back(number);
        }
        cout << max_multiply(numbers) << endl;
    }

}