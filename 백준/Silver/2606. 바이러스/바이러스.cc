#include <bits/stdc++.h>

using namespace std;

vector<int> l[100];
bool w[100];
int cnt;

void dfs(int x) {
    w[x - 1] = true;
    int y;
    for (int i = 0; i < l[x - 1].size(); i++) {
        y = l[x - 1][i];
        if (!w[y - 1]) {
            cnt++;
            dfs(y);
        }
    }
}

// 2606번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, a, b;
    cin >> n;
    cin >> m;
    cnt = 0;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        l[a - 1].push_back(b);
        l[b - 1].push_back(a);
    }
    dfs(1);
    cout << cnt;
}