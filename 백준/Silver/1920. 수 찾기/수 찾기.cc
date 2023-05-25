#include <bits/stdc++.h>

using namespace std;

// 1920번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, num, lo, hi, mid;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        lo = 0;
        hi = n - 1;
        for (;;) {
            mid = (lo + hi) / 2;
            if (a[mid] == num) {
                cout << "1\n";
                break;
            } else if (a[mid] > num) {
                hi = mid;
            } else if (a[mid] < num) {
                lo = mid;
            }
            if (lo + 1 == hi) {
                if (a[hi] == num || a[lo] == num) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
                break;
            }
        }
    }
    return 0;
}