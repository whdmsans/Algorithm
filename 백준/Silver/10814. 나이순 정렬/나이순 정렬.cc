#include <bits/stdc++.h>

using namespace std;

// 10814번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int a[n], p[n];
    string s[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> s[i];
        p[i] = a[i];
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (p[i] == a[j]) {
                cout << a[j] << " " << s[j] << "\n";
                a[j] = -1;
                break;
            }
        }
    }
}