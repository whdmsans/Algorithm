#include <bits/stdc++.h>

using namespace std;

// 18258번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    queue<int> queue1;
    string s;
    cin >> N;
    cin.ignore();
    for (; N-- > 0;) {
        getline(cin, s);
        if (s.find("push") == 0) {
            queue1.push(stoi(s.substr(5, s.length())));
        } else if (s.find("pop") == 0) {
            if (queue1.empty()) {
                cout << "-1\n";
            } else {
                cout << queue1.front() << "\n";
                queue1.pop();
            }
        } else if (s.find("size") == 0) {
            cout << queue1.size() << "\n";
        } else if (s.find("empty") == 0) {
            if (queue1.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (s.find("front") == 0) {
            if (queue1.empty()) {
                cout << "-1\n";
            } else {
                cout << queue1.front() << "\n";
            }
        } else if (s.find("back") == 0) {
            if (queue1.empty()) {
                cout << "-1\n";
            } else {
                cout << queue1.back() << "\n";
            }
        }
    }
}