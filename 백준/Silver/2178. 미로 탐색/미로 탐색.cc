#include <bits/stdc++.h>

using namespace std;

int N, M;
string board[100];
int cnt[100][100] = {0};
int Move[5] = {0, 1, 0, -1, 0};

void dfs(int fx, int fy) {
    int x, y;
    for (int i = 0; i < 4; i++) {
        x = fx + Move[i];
        if (x < 0 || x >= N) {
            continue;
        }
        y = fy + Move[i + 1];
        if (y < 0 || y >= M) {
            continue;
        }
        if (board[x][y] == '0') {
            continue;
        }
        if (cnt[x][y] == 0 || cnt[x][y] > cnt[fx][fy] + 1) {
            cnt[x][y] = cnt[fx][fy] + 1;
            dfs(x, y);
        }
    }
}

// 2178번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    cnt[0][0] = 1;
    dfs(0, 0);
    cout << cnt[N - 1][M - 1];
}
