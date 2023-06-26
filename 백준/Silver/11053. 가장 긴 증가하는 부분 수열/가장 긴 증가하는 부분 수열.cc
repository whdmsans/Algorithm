//11053
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, cnt;
    int arr[1000];
    int dp[1000];
    cin >> N;
    cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cnt = max(cnt, dp[i]);
    }
    cout << cnt;
}
