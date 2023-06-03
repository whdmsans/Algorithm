#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    char c[101];
    cin >> c;
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] > 91) {
            c[i] = c[i] - 32;
        }
        else {
            c[i] = c[i] + 32;
        }
    }
    cout << c;
}