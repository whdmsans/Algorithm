#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[101][100001] = {0};
int W[101], V[101];

// 12865번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> V[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - W[i - 1] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i - 1]] + V[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][K];
}
