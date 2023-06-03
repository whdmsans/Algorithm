#include <bits/stdc++.h>

using namespace std;

// 9461번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, n;
    long long dp[100] = {1, 1, 1, 2, 2};
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 5; j < n; j++) {
            if (dp[j] != 0) {
                continue;
            }
            dp[j] = dp[j - 1] + dp[j - 5];
        }
        cout << dp[n - 1] << "\n";
    }
}