#include <bits/stdc++.h>

using namespace std;

int R, C, result;
int moving[6] = {0, 0, 1, -1, 0, 0};
int visited[26] = {0};
string board[20];

void dfs(int x, int y, int cnt) {
    int dx, dy;
    visited[board[x][y] - 'A'] = 1;
    result = max(result, cnt);
    for (int i = 0; i < 4; i++) {
        dx = x + moving[i];
        dy = y + moving[i + 2];
        if (dx < 0 || dy < 0 || dx >= R || dy >= C || visited[board[dx][dy] - 'A'] != 0) {
            continue;
        }
        dfs(dx, dy, cnt + 1);
    }
    visited[board[x][y] - 'A'] = 0;
    return;
}

// 1987번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> s;
        board[i] = s;
    }
    result = 0;
    dfs(0, 0, 1);
    cout << result;
}
