#include <bits/stdc++.h>

using namespace std;

// 1620번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, i;
    cin >> n >> m;
    string a[n];
    string s;
    map<string, int> map1;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        map1.insert(make_pair(a[i], i + 1));
    }
    for (i = 0; i < m; i++) {
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9') {
            cout << a[stoi(s) - 1] << "\n";
        } else {
            cout << map1.find(s)->second << "\n";
        }
    }
}