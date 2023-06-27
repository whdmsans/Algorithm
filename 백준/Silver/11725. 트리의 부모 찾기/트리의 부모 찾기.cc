#include <bits/stdc++.h>

using namespace std;

int N, x, y;
vector<int> v[100001];
int visited[100001] = {0};
int arr[100001] = {0};

void bfs() {
    queue<int> q;
    visited[1] = 1;
    q.push(1);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i: v[x]) {
            if (visited[i] == 0) {
                q.push(i);
                visited[i] = visited[x] + 1;
                arr[i] = x;
            }
        }
    }
}

// 11725번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs();
    for (int i = 2; i <= N; i++) {
        cout << arr[i] << "\n";
    }
}
