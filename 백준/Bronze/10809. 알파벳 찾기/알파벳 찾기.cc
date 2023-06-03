#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        if (s.find(i + 'a') == string::npos) {
            cout << "-1 ";
        }
        else {
            cout << s.find(i + 'a') << " ";
        }
    }
}