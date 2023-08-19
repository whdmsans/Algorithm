#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int N;
int color[1000][3];
int dp[1000][3];

// 17404번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int result = INT_MAX;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> color[i][j];
        }
    }
    for (int cc = 0; cc < 3; cc++) {
        for (int i = 0; i < 3; i++) {
            if (i == cc) {
                dp[0][i] = color[0][i];
            } else {
                dp[0][i] = MAX;
            }
        }
        for (int i = 1; i < N; i++) {
            dp[i][0] = color[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = color[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = color[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }
        for (int i = 0; i < 3; i++) {
            if (i == cc) {
                continue;
            } else {
                result = min(result, dp[N - 1][i]);
            }
        }
    }
    cout << result;
    return 0;
}