#include <bits/stdc++.h>

using namespace std;

// 9012번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, i, j;
    string s;
    stack<int> stack1;
    cin >> t;
    cin.ignore();
    for (i = 0; i < t; i++) {
        getline(cin, s);
        for (j = 0; j < s.length(); j++) {
            if (s[j] == '(') {
                stack1.push(1);
            } else if (s[j] == ')') {
                if (stack1.empty()) {
                    break;
                }
                stack1.pop();
            }
        }
        if (j == s.length() && stack1.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            for (; !stack1.empty();) {
                stack1.pop();
            }
        }
    }
}