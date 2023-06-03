#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, c1;
    cin >> N;
    for (c1 = N / 5; (N - (5 * c1)) % 3 != 0;c1--) {
        if (c1 <= 0) {
            cout << "-1";
            return 0;
        }
    }
    cout << c1 + ((N - (5 * c1)) / 3);
}