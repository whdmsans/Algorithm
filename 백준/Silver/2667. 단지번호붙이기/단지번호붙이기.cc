#include <bits/stdc++.h>

using namespace std;

int N, c;
string board[25];
vector<int> cnt;
int movePiont[6] = {-1, 1, 0, 0, -1, 1};

void dfs(int x, int y, int c) {
    board[x][y] = '0';
    cnt[c]++;
    int mx, my;
    for (int i = 0; i < 4; i++) {
        mx = x + movePiont[i];
        my = y + movePiont[i + 2];
        if (mx < 0 || my < 0 || mx >= N || my >= N) {
            continue;
        }
        if (board[mx][my] == '0') {
            continue;
        }
        dfs(mx, my, c);
    }
}

// 2667번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    c = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '1') {
                cnt.push_back(0);
                dfs(i, j, c++);
            }
        }
    }
    cout << c << "\n";
    sort(cnt.begin(), cnt.end());
    for (int i = 0; i < c; i++) {
        cout << cnt[i] << "\n";
    }
}
