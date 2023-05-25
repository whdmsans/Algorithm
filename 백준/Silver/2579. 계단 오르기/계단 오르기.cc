#include <bits/stdc++.h>

using namespace std;

// 2579번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    long long score;
    int arr[n];
    long long dp[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    if (arr[0] > arr[1]) {
        dp[2] = arr[0] + arr[2];
    } else {
        dp[2] = arr[1] + arr[2];
    }
    for (int i = 3; i < n; i++) {
        if (dp[i - 2] > dp[i - 3] + arr[i - 1]) {
            dp[i] = dp[i - 2] + arr[i];
        } else {
            dp[i] = dp[i - 3] + arr[i - 1] + arr[i];
        }
    }
    cout << dp[n - 1];
}