#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j < N - i - 1) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        cout << "\n";
    }
}