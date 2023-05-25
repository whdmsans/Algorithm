#include <bits/stdc++.h>

using namespace std;

// 1541번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s, s1;
    s1 = "";
    long long num[25] = {0};
    int index = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+') {
            num[index] += stoi(s1);
            s1 = "";
        } else if (s[i] == '-') {
            num[index++] += stoi(s1);
            s1 = "";
        } else {
            s1 += s[i];
        }
    }
    num[index] += stoi(s1);
    for (int i = 1; i < 25; i++) {
        num[0] -= num[i];
    }
    cout << num[0];
}
