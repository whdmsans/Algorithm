#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int d(int x) {
    int sum = x;
    for (;;) {
        sum = sum + x % 10;
        x = x / 10;
        if (x == 0) {
            break;
        }
    }
    return sum;
}

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (d(i) == n) {
            cout << i;
            break;
        }
        else if (i == n - 1) {
            cout << "0";
        }
    }
}