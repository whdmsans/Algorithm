#include <bits/stdc++.h>

using namespace std;

int V, result, node;
vector<pair<int, int>> edge[100001];
int visited[100001] = {0};

void dfs(int x, int dist) {
    if (result < dist) {
        node = x;
        result = dist;
    }
    visited[x] = 1;
    for (pair<int, int> p: edge[x]) {
        if (visited[p.first] == 0) {
            dfs(p.first, p.second + dist);
        }
    }
    visited[x] = 0;
}

// 1167번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, c;
    cin >> V;
    for (int i = 1; i <= V; i++) {
        cin >> a;
        cin >> b;
        while (b != -1) {
            cin >> c;
            edge[a].push_back(make_pair(b, c));
            cin >> b;
        }
    }
    result = 0;
    dfs(1, 0);
    dfs(node, 0);
    cout << result;
    return 0;
}