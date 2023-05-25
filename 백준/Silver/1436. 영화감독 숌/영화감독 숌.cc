#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, r, i;
    string s;
    cin >> n;
    i = 0;
    r = 660;
    for (;;) {
        s = to_string(r);
        if (s.find("666") != string::npos) {
            i++;
        }
        if (i >= n) {
            break;
        }
        r++;
    }
    cout << r;
}