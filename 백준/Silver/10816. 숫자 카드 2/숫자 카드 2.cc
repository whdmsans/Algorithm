#include <bits/stdc++.h>

using namespace std;

// 10773번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, i, b;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> b;
        cout << upper_bound(a, a + n, b) - lower_bound(a, a + n, b) << " ";
    }
}