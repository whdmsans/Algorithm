#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

int N, M;
int moving[6] = {0, 0, 1, -1, 0, 0};
int board[101][101];
int visited[101][101];

int func() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = board[i][j];
        }
    }
    int x, y, dx, dy, cnt;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            dx = x + moving[i];
            dy = y + moving[i + 2];
            if (dx < 0 || dy < 0 || dx >= N || dy >= M) {
                continue;
            }
            if (board[dx][dy] == 1) {
                visited[dx][dy]++;
            } else if (visited[dx][dy] == 0) {
                q.push(make_pair(dx, dy));
                visited[dx][dy] = 1;
            }
        }
    }
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                if (visited[i][j] >= 3) {
                    board[i][j] = 0;
                } else {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

// 2638번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for (T = 1; func() != 0; T++) {}
    cout << T;
    return 0;
}
