#include <bits/stdc++.h>

using namespace std;

// 1149번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, R, G, B, r;
    long long RGB[1001][3];

    cin >> N;
    for (int i = 0; i < 3; i++) {
        RGB[0][i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        cin >> R >> G >> B;
        RGB[i][0] = min(RGB[i - 1][1], RGB[i - 1][2]) + R;
        RGB[i][1] = min(RGB[i - 1][0], RGB[i - 1][2]) + G;
        RGB[i][2] = min(RGB[i - 1][0], RGB[i - 1][1]) + B;
    }
    RGB[N][0] = min(RGB[N][0], RGB[N][1]);
    RGB[N][0] = min(RGB[N][0], RGB[N][2]);
    cout << RGB[N][0];
}
