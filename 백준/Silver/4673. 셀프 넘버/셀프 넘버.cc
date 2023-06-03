#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int d(int x) {
    return x + x / 1000 + (x / 100) % 10 + (x / 10) % 10 + x % 10;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool a[10000] = { 0, };
    
    for (int i = 0; i < 10000; i++) {
        if (d(i + 1) <= 10000) {
            a[d(i + 1) - 1] = 1;
        }
    }
    for (int i = 0; i < 10000; i++) {
        if (a[i] == 0) {
            cout << i + 1 << "\n";
        }
    }
}