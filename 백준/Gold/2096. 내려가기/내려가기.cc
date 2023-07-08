#include <bits/stdc++.h>

using namespace std;

int N;
int num;
int MAX[2][3];
int MIN[2][3];

// 2096번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> num;
            if (i != 0) {
                if (j == 2) {
                    MAX[i % 2][j] = num + max(MAX[(i - 1) % 2][j], MAX[(i - 1) % 2][j - 1]);
                    MIN[i % 2][j] = num + min(MIN[(i - 1) % 2][j], MIN[(i - 1) % 2][j - 1]);
                } else {
                    MAX[i % 2][j] = num + max(MAX[(i - 1) % 2][j], MAX[(i - 1) % 2][j + 1]);
                    MIN[i % 2][j] = num + min(MIN[(i - 1) % 2][j], MIN[(i - 1) % 2][j + 1]);
                    if (j == 1) {
                        MAX[i % 2][j] = max(MAX[i % 2][j], num + MAX[(i - 1) % 2][j - 1]);
                        MIN[i % 2][j] = min(MIN[i % 2][j], num + MIN[(i - 1) % 2][j - 1]);
                    }
                }
            } else {
                MAX[i % 2][j] = num;
                MIN[i % 2][j] = num;
            }
        }
    }
    cout << max(max(MAX[(N - 1) % 2][0], MAX[(N - 1) % 2][1]), MAX[(N - 1) % 2][2]) << "\n";
    cout << min(min(MIN[(N - 1) % 2][0], MIN[(N - 1) % 2][1]), MIN[(N - 1) % 2][2]) << "\n";
}
