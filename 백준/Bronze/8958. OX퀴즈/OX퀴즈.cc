#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    int count = 0;
    int score = 0;
    cin >> t;
    string s;
    for (int i = 0; i < t; i++) {
        cin >> s;
        score = 0;
        count = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'O') {
                count++;
                score += count;
            }
            else if (s[j] == 'X') {
                count = 0;
            }
        }
        cout << score << "\n";
    }
}