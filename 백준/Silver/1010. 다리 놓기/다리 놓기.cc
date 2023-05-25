#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    int T, N, M;
    int R;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        R = 1;
        for (int j = 0; j < N; j++) {
            R *= (M - j);
            R /= (j + 1);
        }
        cout << R << "\n";
    }
}