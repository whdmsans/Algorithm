#include <bits/stdc++.h>

using namespace std;

int getDistance(string s1, string s2, string s3) {
    int distantce = 0;
    for (int i = 0; i < 4; i++) {
        if (s1[i] != s2[i]) {
            distantce++;
        }
        if (s2[i] != s3[i]) {
            distantce++;
        }
        if (s3[i] != s1[i]) {
            distantce++;
        }
    }
    return distantce;
}

// 20529번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, N, minDistance;
    string s;
    vector<string> sv1;
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> s;
            sv1.push_back(s);
        }
        if (N > 32) {
            cout << "0\n";
            continue;
        }
        minDistance = getDistance(sv1[0], sv1[1], sv1[2]);
        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    minDistance = min(minDistance, getDistance(sv1[i], sv1[j], sv1[k]));
                }
            }
        }
        cout << minDistance << "\n";
        sv1.clear();
    }
}
