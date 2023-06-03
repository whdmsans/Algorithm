#include <bits/stdc++.h>

using namespace std;

// 17626번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
        for (int j = 2; j * j <= i; j++) {
            if (dp[i] > 1 + dp[i - j * j]) {
                dp[i] = 1 + dp[i - j * j];
            }
        }
    }
    cout << dp[n];
}