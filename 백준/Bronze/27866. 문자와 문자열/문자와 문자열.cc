#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    char s[1001];
    int i;
    cin >> s;
    cin >> i;
    cout << s[i-1];
}