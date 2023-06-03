#include <bits/stdc++.h>

using namespace std;

// 9095번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int dp[10];

    int t, n;
    cin >> t;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i < 10; i++) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n - 1] << "\n";
    }
}