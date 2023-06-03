#include <bits/stdc++.h>

using namespace std;

// 17219번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    map<string, string> map1;
    string s, s1;
    for (int i = 0; i < n; i++) {
        cin >> s >> s1;
        map1.insert(make_pair(s, s1));
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        cout << map1.find(s)->second << "\n";
    }
}