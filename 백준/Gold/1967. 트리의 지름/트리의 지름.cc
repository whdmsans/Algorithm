#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;

int N;
int parentNode[10001] = {0};
int visited[10001] = {0};
vector<int> leafNode;
vector<pair<int, int>> edge[10001];

int dfs(int x) {
    visited[x] = 1;
    int result = 0;
    for (pair<int, int> p: edge[x]) {
        if (visited[p.first] == 0) {
            result = max(result, dfs(p.first) + p.second);
        }
    }
    return result;
}

// 1967번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    int a, b, c, result;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        parentNode[a] = 1;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    for (int i = 1; i <= N; i++) {
        if (parentNode[i] == 0) {
            leafNode.push_back(i);
        }
    }
    result = 0;
    for (int i = 0; i < leafNode.size(); i++) {
        memset(visited, 0, 10001 * sizeof(int));
        result = max(result, dfs(leafNode[i]));
    }
    cout << result;
}
