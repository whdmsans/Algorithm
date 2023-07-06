#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1025][1025], dp[1025][1025];

// 11660번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);


    int x1, y1, x2, y2;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if (i == 0 && j == 0) {
                dp[i][j] = arr[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + arr[i][j];
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
            }
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x2][y1 - 1] - dp[x1 - 1][y2] << "\n";
    }
}
