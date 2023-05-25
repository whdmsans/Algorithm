#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    for (;;) {
        cin >> s;
        if (s == "0") {
            break;
        }
        else if (s.length() == 1) {
            cout << "yes\n";
        }
        else {
            for (int i = 0; i < s.length() / 2; i++) {
                if (s[s.length() - i - 1] != s[i]) {
                    cout << "no\n";
                    break;
                }
                else if (i == s.length() / 2 - 1) {
                    cout << "yes\n";
                }
            }
        }
    }
}