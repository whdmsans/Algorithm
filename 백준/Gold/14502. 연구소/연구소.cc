#include <bits/stdc++.h>

using namespace std;

int N, M, VN, result;

int moving[6] = {0, 0, 1, -1, 0, 0};
int board[9][9];
int visited[9][9];
pair<int, int> V[11];

void dfs(int x, int y) {
    visited[x][y] = 1;
    int dx, dy;
    for (int i = 0; i < 4; i++) {
        dx = x + moving[i];
        dy = y + moving[i + 2];
        if (dx < 0 || dy < 0 || dx >= N || dy >= M) {
            continue;
        }
        if (visited[dx][dy] == 1) {
            continue;
        }
        dfs(dx, dy);
    }
}

void check() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = min(board[i][j], 1);
        }
    }
    for (int i = 0; i < VN; i++) {
        dfs(V[i].first, V[i].second);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                cnt++;
            }
        }
    }
    result = max(result, cnt);
}

void func(int x, int y, int n) {
    if (n == 0) {
        check();
        return;
    }
    for (int j = 0; j < M; j++) {
        if (board[x][j] == 0) {
            board[x][j] = 1;
            func(x, j, n - 1);
            board[x][j] = 0;
        }
    }
    for (int i = x + 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                func(i, j, n - 1);
                board[i][j] = 0;
            }
        }
    }
}

// 14502번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    VN = 0;
    result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                V[VN++] = make_pair(i, j);
            }
        }
    }
    func(0, 0, 3);
    cout << result;
}