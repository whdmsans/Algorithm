#include <bits/stdc++.h>

using namespace std;

// 1764번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, low, mid, high;
    cin >> n >> m;
    string a[n];
    string b[m];
    vector<string> v1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b, b + m);
    for (int i = 0; i < n; i++) {
        for (low = 0, high = m - 1; low <= high;) {
            mid = (low + high) / 2;
            if (a[i].compare(b[mid]) == 0) {
                v1.push_back(b[mid]);
                break;
            } else if (a[i] > b[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    sort(v1.begin(), v1.end());
    cout << v1.size() << "\n";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << "\n";
    }
}