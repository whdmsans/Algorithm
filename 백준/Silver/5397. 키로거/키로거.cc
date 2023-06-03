#include <bits/stdc++.h>

using namespace std;

// 5397번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, i, j;
    cin >> t;
    string s;
    stack<char> CL, CR;

    for (i = 0; i < t; i++) {
        cin >> s;
        for (j = 0; j < s.length(); j++) {
            switch (s[j]) {
                case '<':
                    if (!CL.empty()) {
                        CR.push(CL.top());
                        CL.pop();
                    }
                    break;
                case '>':
                    if (!CR.empty()) {
                        CL.push(CR.top());
                        CR.pop();
                    }
                    break;
                case '-':
                    if (!CL.empty()) {
                        CL.pop();
                    }
                    break;
                default:
                    CL.push(s[j]);
                    break;
            }
        }
        // 출력
        for (j = CL.size(); j != 0; j--) {
            CR.push(CL.top());
            CL.pop();
        }
        for (j = CR.size(); j != 0; j--) {
            cout << CR.top();
            CR.pop();
        }
        cout << "\n";
    }

    return 0;
}