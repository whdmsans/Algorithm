#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

int len = 1;
int arr[100001];
int movingValue[5][5] = {{1, 2, 2, 2, 2},
                         {0, 1, 3, 4, 3},
                         {0, 3, 1, 3, 4},
                         {0, 4, 3, 1, 3},
                         {0, 3, 4, 3, 1}};
int dp[100001][5][5];

int func(int cur, int left, int right) {
    if (cur == len - 1) {
        return 0;
    }
    if ((left != 0 && right != 0) && left == right) {
        return 400001;
    }
    if (dp[cur][left][right] == -1) {
        dp[cur][left][right] = min(func(cur + 1, arr[cur + 1], right) + movingValue[left][arr[cur + 1]],
                                   func(cur + 1, left, arr[cur + 1]) + movingValue[right][arr[cur + 1]]);
    }
    return dp[cur][left][right];
}

// 2342번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));
    cin >> arr[len++];
    while (arr[len - 1] != 0) {
        cin >> arr[len++];
    }
    cout << func(0, 0, 0);
    return 0;
}