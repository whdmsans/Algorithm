#include <bits/stdc++.h>

using namespace std;

// 11650번

int WB_check(string b[], int n, int m) {
    string WB[8] = {
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW"
    };
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (b[i + n][j + m] != WB[i][j]) {
                count++;
            }
        }
    }
    return count;
}

int BW_check(string b[], int n, int m) {
    string BW[8] = {
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB",
            "BWBWBWBW",
            "WBWBWBWB"
    };
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (b[i + n][j + m] != BW[i][j]) {
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, countWB, countBW;
    cin >> n >> m;
    string b[n];
    string s;
    int min;
    for (int i = 0; i < n; i++) {
        cin >> s;
        b[i] = s;
    }
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            countWB = WB_check(b, i, j);
            countBW = BW_check(b, i, j);
            if (i == 0 && j == 0) {
                min = countWB;
            }
            if (countWB > countBW) {
                countWB = countBW;
            }
            if (min > countWB) {
                min = countWB;
            }
        }
    }
    cout << min;
}