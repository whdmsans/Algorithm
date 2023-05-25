#include <bits/stdc++.h>

using namespace std;

pair<int, int> DP[41] = {{1, 0},
                         {0, 1}};

// 1003번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 2; j <= n; j++) {
            DP[j].first = DP[j - 1].first + DP[j - 2].first;
            DP[j].second = DP[j - 1].second + DP[j - 2].second;
        }
        cout << DP[n].first << " " << DP[n].second << "\n";
    }
}