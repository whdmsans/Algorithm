#include <bits/stdc++.h>

using namespace std;

// 1406번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, i;
    string s;
    stack<char> stackR, stackL;

    cin >> s;
    for (i = 0; i < s.length(); i++) {
        stackL.push(s[i]);
    }

    cin >> t;
    cin.ignore();
    for (i = 0; i < t; i++) {
        getline(cin, s);
        switch (s[0]) {
            case 'L':
                if (!stackL.empty()) {
                    stackR.push(stackL.top());
                    stackL.pop();
                }
                break;
            case 'D':
                if (!stackR.empty()) {
                    stackL.push(stackR.top());
                    stackR.pop();
                }
                break;
            case 'B':
                if (!stackL.empty()) {
                    stackL.pop();
                }
                break;
            case 'P':
                stackL.push(s[2]);
                break;
        }
    }

    // 출력
    for (; !stackL.empty();) {
        stackR.push(stackL.top());
        stackL.pop();
    }
    for (i = 0; !stackR.empty(); i++) {
        cout << stackR.top();
        stackR.pop();
    }
    return 0;
}