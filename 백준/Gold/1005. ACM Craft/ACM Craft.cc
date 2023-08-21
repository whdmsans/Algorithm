#include <bits/stdc++.h>

using namespace std;

int N, K;
int cost[1001];
int totalCost[1001];
int requestBuilding[1001];
vector<int> building[1001];


// 1005번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, x, y, w;
    cin >> T;
    queue<int> q;
    while (T-- > 0) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> cost[i];
            totalCost[i] = cost[i];
            requestBuilding[i] = 0;
            building[i].clear();
        }
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            building[x].push_back(y);
            requestBuilding[y]++;
        }
        for (int i = 1; i <= N; i++) {
            if (requestBuilding[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            x = q.front();
            q.pop();
            for (int Building: building[x]) {
                requestBuilding[Building]--;
                totalCost[Building] = max(totalCost[Building], totalCost[x] + cost[Building]);
                if (requestBuilding[Building] == 0) {
                    q.push(Building);
                }
            }
        }
        cin >> w;
        cout << totalCost[w] << "\n";
    }
    return 0;
}