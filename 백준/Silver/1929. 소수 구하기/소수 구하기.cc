#include <bits/stdc++.h>

using namespace std;

// 1929번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> m >> n;
    bool a[n];
    for (int i = 0; i <= n; i++) {
        a[i] = true;
    }
    a[0] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!a[i - 1]) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            a[j - 1] = false;
        }
    }
    for (int i = m; i <= n; i++) {
        if (a[i - 1]) {
            cout << i << "\n";
        }
    }
}