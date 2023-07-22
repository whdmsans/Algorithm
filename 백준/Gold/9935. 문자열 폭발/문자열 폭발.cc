#include <bits/stdc++.h>

using namespace std;

// 9935번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int s_len, b_len;
    int index = 0;
    string s, b;
    cin >> s;
    cin >> b;
    s_len = s.length();
    b_len = b.length();
    char t[1000001];
    for (int i = 0; i < s_len; i++) {
        t[index++] = s[i];
        if (index >= b_len) {
            int j;
            int index1 = index - b_len;
            for (j = 0; j < b_len; j++) {
                if (b[j] != t[index1 + j]) {
                    break;
                }
            }
            if (j == b_len) {
                index = index1;
            }
        }
    }
    if (index == 0) {
        cout << "FRULA";
    } else {
        for (int i = 0; i < index; i++) {
            cout << t[i];
        }
    }
}