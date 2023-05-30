#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> v[101];
bool visited[101];

int bfs(int x) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, 0));
    pair<int, int> n;
    for (int i = 1; !q.empty(); i++) {
        n = q.front();
        visited[n.first] = true;
        q.pop();
        for (int j = 0; j < v[n.first].size(); j++) {
            if (!visited[v[n.first][j].first]) {
                visited[v[n.first][j].first] = true;
                q.push(make_pair(v[n.first][j].first, n.second + 1));
                cnt += n.second + 1;
            }
        }
    }
    return cnt;
}

// 1389번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b;
    cin >> N >> M;
    pair<int, int> arr[101];
    for (; M-- > 0;) {
        cin >> a >> b;
        v[a].push_back(make_pair(b, 1));
        v[b].push_back(make_pair(a, 1));
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 100; j++) {
            visited[j + 1] = false;
        }
        arr[i] = make_pair(bfs(i), i);
    }
    sort(arr + 1, arr + N + 1);
    cout << arr[1].second << "\n";
}
