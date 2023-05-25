#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    int count = 1;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            count++;
        }
    }
    if (s[0] == ' ') {
        count--;
    }
    if (s[s.length() - 1] == ' ') {
        count--;
    }
    cout << count;
}