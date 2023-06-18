#include <bits/stdc++.h>

using namespace std;

int board[101];
int mm[101] = {0};
int visited[101] = {0};

void bfs(int x, int c) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, c));
    visited[x] = 1;
    while (!q.empty()) {
        x = q.front().first;
        c = q.front().second;
        q.pop();
        if (x == 100) {
            cout << c;
            break;
        }
        for (int i = 1; i < 7; i++) {
            if (x + i <= 100 && visited[x + i] == 0) {
                visited[x + i] = 1;
                if (mm[x + i] != 0) {
                    q.push(make_pair(mm[x + i], c + 1));
                } else {
                    q.push(make_pair(x + i, c + 1));
                }
            }
        }
    }
}

// 16928번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, x, y;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        mm[x] = y;
    }
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        mm[x] = y;
    }
    bfs(1, 0);
}
