#include <bits/stdc++.h>

using namespace std;

// 1920번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    stack<int> stack1;
    string s;
    string ends = ".";
    int i;
    for (;;) {
        getline(cin, s);
        if (s.compare(ends) == 0) {
            break;
        }
        for (i = 0; s[i] != '.'; i++) {
            if (s[i] == '(') {
                stack1.push(1);
            } else if (s[i] == '[') {
                stack1.push(2);
            } else if (s[i] == ')') {
                if (stack1.empty() || stack1.top() == 2) {
                    break;
                } else {
                    stack1.pop();
                }
            } else if (s[i] == ']') {
                if (stack1.empty() || stack1.top() == 1) {
                    break;
                } else {
                    stack1.pop();
                }
            }
        }
        if (s[i] == '.' && stack1.empty()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
            for (; !stack1.empty();) {
                stack1.pop();
            }
        }
    }
}