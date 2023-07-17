#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;

int V, E, K;
int dist[20001];
vector<pair<int, int>> edge[20001];

void dijkstra(int start) {
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    int nowDistance, nowNode;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        nowNode = pq.top().second;
        nowDistance = -pq.top().first;
        pq.pop();
        if (dist[nowNode] < nowDistance) {
            continue;
        }
        for (pair<int, int> p: edge[nowNode]) {
            if (dist[p.first] > p.second + nowDistance) {
                pq.push({-(p.second + nowDistance), p.first});
                dist[p.first] = p.second + nowDistance;
            }
        }
    }
}

// 1753번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> V >> E;
    cin >> K;

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }
    dijkstra(K);
    for (int i = 1; i <= V; i++) {
        if (dist[i] != INF) { cout << dist[i] << "\n"; }
        else { cout << "INF\n"; }
    }
}
