#include <bits/stdc++.h>

using namespace std;

int N, M;
int moving[6] = {0, 0, 1, -1, 0, 0};
int board[20][20];
int dist[20][20];
pair<int, int> place;

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if (dist[p1.first][p1.second] > dist[p2.first][p2.second]) {
            return true;
        } else if (dist[p1.first][p1.second] == dist[p2.first][p2.second]) {
            if (p1.first > p2.first) {
                return true;
            } else if (p1.first == p2.first) {
                if (p1.second > p2.second) {
                    return true;
                }
                return false;
            }
            return false;
        }
        return false;
    }
};

int bfs() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = 0;
        }
    }
    int x, y, dx, dy;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    x = place.first;
    y = place.second;
    pq.push(make_pair(x, y));
    while (!pq.empty()) {
        x = pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (!(x == place.first && y == place.second) && board[x][y] != 0 &&
            board[x][y] < board[place.first][place.second]) {
            board[x][y] = board[place.first][place.second];
            board[place.first][place.second] = 0;
            place = make_pair(x, y);
            return dist[x][y];
        }
        for (int i = 0; i < 4; i++) {
            dx = x + moving[i];
            dy = y + moving[i + 2];
            if (dx < 0 || dy < 0 || dx >= N || dy >= N) {
                continue;
            }
            if (board[place.first][place.second] < board[dx][dy]) {
                continue;
            }
            if (dist[dx][dy] == 0) {
                dist[dx][dy] = dist[x][y] + 1;
                pq.push(make_pair(dx, dy));
            }
        }
    }
    return -1;
}

// 16236번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T = 0;
    int time;
    cin >> N;
    M = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                board[i][j] = 2;
                place = make_pair(i, j);
            }
        }
    }
    for (int i = 1; (time = bfs()) != -1; i++) {
        T += time;
        if (i == board[place.first][place.second]) {
            i = 0;
            board[place.first][place.second]++;
        }
//        cout << i << "\n";
//        for (int k = 0; k < N; k++) {
//            for (int j = 0; j < N; j++) {
//                cout << board[k][j] << " ";
//            }
//            cout << "\n";
//        }
    }
    cout << T;
    return 0;
}