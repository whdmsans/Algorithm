#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    string s, a;
    for (int i = 0; i < T; i++) {
        cin >> s;
        if (i == 0) {
            a = s;
            continue;
        }
        for (int j = 0; j < a.length(); j++) {
            if (a[j] == '?') {
                continue;
            }
            else if (a[j] != s[j]) {
                a[j] = '?';
            }
        }
    }
    cout << a;
}