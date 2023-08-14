#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pair_ii;

int N, M;
int visited[100001] = {0};
vector<pair_ii> edge[100001];
priority_queue<pair_ii, vector<pair_ii>, greater<pair_ii>> pq;

// 1647번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int A, B, C, node, cost, result, maxCost;
    maxCost = 0;
    result = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edge[A].push_back(make_pair(B, C));
        edge[B].push_back(make_pair(A, C));
    }
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        cost = pq.top().first;
        node = pq.top().second;
        pq.pop();
        if (visited[node] == 1) {
            continue;
        }
        maxCost = max(maxCost, cost);
        visited[node] = 1;
        result += cost;
        for (pair_ii p: edge[node]) {
            pq.push(make_pair(p.second, p.first));
        }
    }
    cout << result - maxCost;
    return 0;
}