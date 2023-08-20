#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[500000];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return find(parent[x]);
}

// 20040번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, result;
    result = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (result == 0) {
            if (find(a) == find(b)) {
                result = i + 1;
            }
            if (find(a) < find(b)) {
                parent[find(b)] = find(a);
            } else {
                parent[find(a)] = find(b);
            }
        }
    }
    cout << result;
    return 0;
}