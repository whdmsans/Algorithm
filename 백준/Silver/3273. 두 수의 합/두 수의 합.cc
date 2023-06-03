#include <bits/stdc++.h>

using namespace std;

// 3273번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x, r, i, j;
    cin >> n;
    int a[n];
    r = 0;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    sort(a, a + n);
    i = 0;
    j = n - 1;
    for (; i < j;) {
        if (a[i] + a[j] == x) {
            r++;
            i++;
            j--;
        } else if (a[i] + a[j] > x) {
            j--;
        } else if (a[i] + a[j] < x) {
            i++;
        }
    }
    cout << r;
}