#include <bits/stdc++.h>

using namespace std;

string s1, s2;
char result[1000];
int LCS[1000][1000] = {0};

void func(int x, int y) {
    if (x < 0 || y < 0 || LCS[x][y] == 0) {
        return;
    }
    if (x == 0) {
        if (LCS[0][y] == LCS[0][y - 1]) {
            func(0, y - 1);
        } else {
            result[LCS[0][y] - 1] = s1[0];
        }
        return;
    }
    if (y == 0) {
        if (LCS[x][0] == LCS[x - 1][0]) {
            func(x - 1, 0);
        } else {
            result[LCS[x][0] - 1] = s2[0];
        }
        return;
    }
    if (LCS[x][y] == LCS[x - 1][y]) {
        func(x - 1, y);
    } else if (LCS[x][y] == LCS[x][y - 1]) {
        func(x, y - 1);
    } else {
        result[LCS[x][y] - 1] = s1[x];
        func(x - 1, y - 1);
    }
}

// 9252번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int maxLength = 0;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (i == 0 || j == 0) {
                if (s1[i] == s2[j]) {
                    LCS[i][j] = 1;
                } else {
                    if (i != 0) {
                        LCS[i][j] = LCS[i - 1][j];
                    } else if (j != 0) {
                        LCS[i][j] = LCS[i][j - 1];
                    }
                }
            } else {
                if (s1[i] == s2[j]) {
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                } else {
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
                }
            }
            maxLength = max(maxLength, LCS[i][j]);
        }
    }
    cout << maxLength;
    if (maxLength != 0) {
        cout << "\n";
        func(s1.length() - 1, s2.length() - 1);
        for (int i = 0; i < maxLength; i++) {
            cout << result[i];
        }
    }
    return 0;
}