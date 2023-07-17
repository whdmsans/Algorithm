#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;

int N;
int d[801];
vector<pair<int, int>> edge[801];

void dijkstra(int start) {
    for (int i = 1; i <= N; i++) {
        d[i] = INF;
    }

    priority_queue<pair<int, int>> pq;

    pq.push({0, start});
    d[start] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) {
            continue;
        }
        for (pair<int, int> p: edge[now]) {
            if (d[p.first] > p.second + dist) {
                pq.push({-(p.second + dist), p.first});
                d[p.first] = p.second + dist;
            }
        }
    }
}


// 1504번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int E, v1, v2, a, b, c;
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    int to_v1, to_v2, v1_to_v2, v1_to_n, v2_to_n;
    dijkstra(1);
    to_v1 = d[v1];
    to_v2 = d[v2];
    dijkstra(v1);
    v1_to_v2 = d[v2];
    v1_to_n = d[N];
    dijkstra(v2);
    v2_to_n = d[N];

//    cout << to_v1 << "\n";
//    cout << to_v2 << "\n";
//    cout << v1_to_v2 << "\n";
//    cout << v1_to_n << "\n";
//    cout << v2_to_n << "\n";

    int result;
    if (to_v1 != INF && to_v2 != INF && v1_to_v2 != INF && v1_to_n != INF && v2_to_n != INF) {
        result = min(to_v1 + v1_to_v2 + v2_to_n, to_v2 + v1_to_v2 + v1_to_n);
    } else if (to_v1 != INF && v1_to_v2 != INF && v2_to_n != INF) {
        result = to_v1 + v1_to_v2 + v2_to_n;
    } else if (to_v2 != INF && v1_to_v2 != INF && v1_to_n != INF) {
        result = to_v2 + v1_to_v2 + v1_to_n;
    } else {
        result = -1;
    }
    cout << result;
}
