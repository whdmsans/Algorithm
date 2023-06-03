#include <bits/stdc++.h>

using namespace std;

// 2805번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    long long m, low, mid, sum, high = 0, max;
    cin >> n >> m;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (high < a[i]) { high = a[i]; }
    }
    low = 0;
    max = 0;
    for (; low <= high;) {
        sum = 0;
        mid = (low + high) / 2;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) {
                sum += a[i] - mid;
            }
        }
        if (sum < m) {
            high = mid - 1;
        } else {
            low = mid + 1;
            if (max < mid) {
                max = mid;
            }
        }
    }
    cout << max;
}