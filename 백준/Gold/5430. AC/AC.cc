#include <bits/stdc++.h>

using namespace std;

// 5430번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, n;
    string s, s1, result, t;
    bool R;
    deque<char> dq;
    cin >> T;
    while (T--) {
        result = "";
        R = false;
        dq.clear();
        cin >> s;
        cin >> n;
        cin >> s1;
        for (int i = 0; i < s1.length(); i++) {
            dq.push_back(s1[i]);
        }
        dq.pop_back();
        dq.pop_front();
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                R = !R;
            } else if (s[i] == 'D') {
                if (n == 0) {
                    R = false;
                    dq.clear();
                    result = "error";
                    break;
                }
                if (n == 1) {
                    dq.clear();
                } else if (!R) {
                    while (dq.front() != ',') {
                        dq.pop_front();
                    }
                    dq.pop_front();
                } else if (R) {
                    while (dq.back() != ',') {
                        dq.pop_back();
                    }
                    dq.pop_back();
                }
                n--;
            }
        }

        if (result.compare("error") != 0) {
            result = "[";
            while (!dq.empty()) {
                if (!R) {
                    result += dq.front();
                    dq.pop_front();
                } else if (R) {
                    if (n > 1) {
                        s = "";
                        while (dq.back() != ',') {
                            s += dq.back();
                            dq.pop_back();
                        }
                        for (int i = 0; i < s.length(); i++) {
                            result += s[s.length() - 1 - i];
                        }
                        result += dq.back();
                        dq.pop_back();
                        n--;
                    }
                    if (n == 1) {
                        s = "";
                        while (!dq.empty()) {
                            s += dq.back();
                            dq.pop_back();
                        }
                        for (int i = 0; i < s.length(); i++) {
                            result += s[s.length() - 1 - i];
                        }
                    }
                }
            }
            result += "]";
        }

        cout << result << "\n";
    }
}
