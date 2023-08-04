#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

int N, M;
string result;
vector<pair<int, int>> edge[1001];
int dist[1001];
int route[1001];

void dijkstra(int start) {
    int cost, num;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    route[start] = 0;
    while (!pq.empty()) {
        cost = -pq.top().first;
        num = pq.top().second;
        pq.pop();
        if (dist[num] < cost) {
            continue;
        }
        for (pair<int, int> p: edge[num]) {
            if (dist[p.first] > cost + p.second) {
                dist[p.first] = cost + p.second;
                pq.push(make_pair(-dist[p.first], p.first));
                route[p.first] = num;
            }
        }
    }
}

// 11779번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    int s, e, c;
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        edge[s].push_back(make_pair(e, c));
    }
    cin >> s >> e;
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dijkstra(s);
    cout << dist[e] << "\n";
    c = 1;
    vector<int> v;
    while (dist[e] != 0) {
        v.push_back(e);
        e = route[e];
        c++;
    }
    v.push_back(e);
    cout << c << "\n";
    for (int i = c - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    return 0;
}