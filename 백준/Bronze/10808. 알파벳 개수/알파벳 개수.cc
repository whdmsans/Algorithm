#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    int a[26] = {0,};

    for (int i = 0; i < s.length(); i++) {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << a[i] << " ";
    }
}