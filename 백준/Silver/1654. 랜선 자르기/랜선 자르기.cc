#include <bits/stdc++.h>

using namespace std;

// 1654번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n, k, low, high, mid, length, max;
    cin >> n >> k;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    low = 1;
    high = max;
    length = 0;
    for (; low <= high;) {
        max = 0;
        mid = (low + high) / 2;
        for (int i = 0; i < n; i++) {
            max += arr[i] / mid;
        }
        if (max < k) {
            high = mid - 1;
        } else if (max >= k) {
            low = mid + 1;
            if (length < mid) {
                length = mid;
            }
        }
    }
    cout << length;
}