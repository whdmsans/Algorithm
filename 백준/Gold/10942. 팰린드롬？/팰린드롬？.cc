#include <bits/stdc++.h>

using namespace std;

int N;
int num[2001];
bool palindrom[2001][2001] = {false};

// 10942번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        palindrom[i][i] = true;
    }
    for (int i = 1; i <= N - 1; i++) {
        if (num[i] == num[i + 1]) {
            palindrom[i][i + 1] = true;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 2; j <= N; j++) {
            if (num[i] == num[j] && palindrom[i + 1][j - 1]) {
                palindrom[i][j] = true;
            }
        }
    }
    int m, s, e;
    cin >> m;
    while (m-- > 0) {
        cin >> s >> e;
        if (palindrom[s][e]) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}