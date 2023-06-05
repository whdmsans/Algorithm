#include <bits/stdc++.h>

using namespace std;

int N, M, cnt;
string board[600];
int visited[600][600] = {0};
int movex[4] = {-1, 1, 0, 0};
int movey[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    if (board[x][y] == 'P') {
        cnt++;
    }
    int a, b;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        a = x + movex[i];
        b = y + movey[i];
        if (a < 0 || a >= N || b < 0 || b >= M) {
            continue;
        } else if (board[a][b] == 'X') {
            continue;
        } else if (visited[a][b] == 1) {
            continue;
        }
        dfs(a, b);
    }
}

// 21736번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int x, y;
    cnt = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        if (board[i].find('I') != string::npos) {
            x = i;
            y = board[i].find('I');
        }
    }
    dfs(x, y);
    if (cnt == 0) {
        cout << "TT";
    } else {
        cout << cnt;
    }
}
