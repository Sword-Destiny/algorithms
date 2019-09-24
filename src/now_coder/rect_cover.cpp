//
// Created by yuanhao on 2019-9-24.
//
#include <iostream>

using namespace std;

int rectCover(int number) {
    if(number == 0){
        return 0;
    }
    if (number == 1) {
        return 1;
    }
    if (number == 2) {
        return 2;
    }
    int dp[number];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < number; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[number - 1] + dp[number - 2];
}

int main() {
    for (int i = 1; i < 100; ++i) {
        cout << rectCover(i) << endl;
    }
}