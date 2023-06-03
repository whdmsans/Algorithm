#include <bits/stdc++.h>

using namespace std;

// 10828번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    stack<int> stack1;
    string s;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (s.find("push") == 0) {
            stack1.push(stoi(s.substr(5, s.length())));
        } else if (s.find("pop") == 0) {
            if (stack1.empty()) {
                cout << "-1\n";
            } else {
                cout << stack1.top() << "\n";
                stack1.pop();
            }
        } else if (s.find("size") == 0) {
            cout << stack1.size() << "\n";
        } else if (s.find("empty") == 0) {
            if (stack1.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (s.find("top") == 0) {
            if (stack1.empty()) {
                cout << "-1\n";
            } else {
                cout << stack1.top() << "\n";
            }
        }
    }
}