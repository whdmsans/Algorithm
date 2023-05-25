#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[50][50] = {0};

void dfs(int x, int y) {
    dp[x][y] = 2;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= 50 || ny < 0 || ny >= 50) {
            continue;
        } else {
            if (dp[nx][ny] == 1) {
                dfs(nx, ny);
            }
        }
    }
}

// 1012번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, k, x, y, cnt;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cnt = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            dp[x][y] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 1) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << "\n";
    }
}