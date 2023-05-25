#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a[9];
    int c = 0;
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
        if (a[c] < a[i]) {
            c = i;
        }
    }
    cout << a[c] << "\n" << c + 1;
}