#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

int n, m;
int bus[101][101];
int minCost[101][101];

// 11404번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                bus[i][j] = 0;
                minCost[i][j] = 0;
                continue;
            }
            bus[i][j] = INF;
            minCost[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        bus[a][b] = min(bus[a][b], c);
        minCost[a][b] = bus[a][b];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || minCost[j][i] == INF) {
                continue;
            }
            for (int k = 1; k <= n; k++) {
                if (i == k || j == k || minCost[i][k] == INF) {
                    continue;
                }
                minCost[j][k] = min(minCost[j][k], minCost[j][i] + minCost[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (minCost[i][j] == INF) {
                cout << "0 ";
            } else {
                cout << minCost[i][j] << " ";
            }
        }
        cout << "\n";
    }
}