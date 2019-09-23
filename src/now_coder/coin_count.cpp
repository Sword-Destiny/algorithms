//
// Created by yuanhao on 2019-9-4.
//
#include <iostream>

using namespace std;

int mod = 1e9 + 7;
int dp[4][100001];

void coin_count(int n, int m) {
    if (m == 10) {
        coin_count(n, 5);
        dp[3][n] = dp[2][n];
        for (int i = 10; i <= n; i += 10) {
            if (dp[2][n - i] == 0)
                coin_count(n - i, 5);
            dp[3][n] += dp[2][n - i];
            dp[3][n] %= mod;
        }
    }
    if (m == 5) {
        if (dp[1][n] == 0)
            coin_count(n, 2);
        dp[2][n] = dp[1][n];
        for (int i = 5; i <= n; i += 5) {
            if (dp[1][n - 1] == 0)
                coin_count(n - i, 2);
            dp[2][n] += dp[1][n - i];
            dp[2][n] %= mod;
        }
    }
    if (m == 2) {
        dp[1][n] = dp[0][n];
        for (int i = 2; i <= n; i += 2) {
            dp[1][n] += 1;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 1;
    }
    coin_count(n, 10);
    cout << dp[3][n] << endl;
}