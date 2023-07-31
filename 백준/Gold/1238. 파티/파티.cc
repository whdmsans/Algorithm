#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

int N, M, X;
int NtoX[1001];
int XtoN[1001];
vector<pair<int, int>> road[1001];
vector<pair<int, int>> roadReversal[1001];

void dijkstra(int x) {
    priority_queue<pair<int, int>> pq;
    int node, distance;
    pq.push(make_pair(0, x));
    NtoX[x] = 0;
    while (!pq.empty()) {
        node = pq.top().second;
        distance = -pq.top().first;
        pq.pop();
        if (distance < NtoX[node]) {
            continue;
        }
        for (pair<int, int> p: road[node]) {
            if (NtoX[p.first] > p.second + distance) {
                NtoX[p.first] = p.second + distance;
                pq.push(make_pair(-(p.second + distance), p.first));
            }
        }
    }
    pq.push(make_pair(0, x));
    XtoN[x] = 0;
    while (!pq.empty()) {
        node = pq.top().second;
        distance = -pq.top().first;
        pq.pop();
        if (distance < XtoN[node]) {
            continue;
        }
        for (pair<int, int> p: roadReversal[node]) {
            if (XtoN[p.first] > p.second + distance) {
                XtoN[p.first] = p.second + distance;
                pq.push(make_pair(-(p.second + distance), p.first));
            }
        }
    }
}

// 1238번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, t, result;
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> t;
        road[a].push_back(make_pair(b, t));
        roadReversal[b].push_back(make_pair(a, t));
    }
    for (int i = 1; i <= N; i++) {
        NtoX[i] = INF;
        XtoN[i] = INF;
    }
    dijkstra(X);
    result = 0;
    for (int i = 1; i <= N; i++) {
        result = max(result, NtoX[i] + XtoN[i]);
    }
    cout << result;
    return 0;
}