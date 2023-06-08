#include <bits/stdc++.h>

using namespace std;

// 5525번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, cnt, index;
    cnt = 0;
    string s;
    string str = "I";
    cin >> N;
    for (int i = 0; i < N; i++) {
        str += "OI";
    }
    cin >> M;
    cin >> s;
    index = s.find(str);
    while (str.length() <= s.length() && index != string::npos) {
        cnt++;
        s = s.substr(index + 2, s.length());
        index = s.find(str);
    }
    cout << cnt;
}
