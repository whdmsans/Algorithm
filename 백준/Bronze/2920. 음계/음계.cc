#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a[8];
    int i;
    int f = 0;
    for (i = 0; i < 8; i++) {
        cin >> a[i];
        if (f == i) {
            if (a[i] == i + 1) {
                f++;
            }
        }
        if (f == -i) {
            if (a[i] == 8 - i) {
                f--;
            }
        }
    }
    if (f == 8) {
        cout << "ascending";
    }
    else if (f == -8) {
        cout << "descending";
    }
    else {
        cout << "mixed";
    }
}