#include <bits/stdc++.h>

using namespace std;

int arr[1000] = {0};
vector<int> vector1[1000];
queue<int> queue1;

void dfs(int v) {
    arr[v - 1] = 1;
    cout << v << " ";
    for (int i = 0; i < vector1[v - 1].size(); i++) {
        if (arr[vector1[v - 1][i] - 1] != 1) {
            dfs(vector1[v - 1][i]);
        }
    }
}

void bfs(int v) {
    arr[v - 1] = 1;
    queue1.push(v);

    for (; !queue1.empty();) {
        v = queue1.front();
        cout << v << " ";
        queue1.pop();

        for (int i = 0; i < vector1[v - 1].size(); i++) {
            if (arr[vector1[v - 1][i] - 1] != 1) {
                queue1.push(vector1[v - 1][i]);
                arr[vector1[v - 1][i] - 1] = 1;
            }
        }
    }
}

// 1260번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, v, a, b;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vector1[a - 1].push_back(b);
        vector1[b - 1].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        sort(vector1[i].begin(), vector1[i].end());
    }
    dfs(v);
    cout << "\n";
    for (int i = 0; i < 1000; i++) {
        arr[i] = 0;
    }
    bfs(v);
}
