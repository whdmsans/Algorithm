#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, i;
    cin >> n;
    for (i = 0; n -  6 * i - 1 > 0 ; i++) {
        n = n - 6 * i;
    }
    cout << i + 1;
}