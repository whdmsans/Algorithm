#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

int N, M, W;

int dist[501];

struct Node {
    int Start, End, Cost;

    Node(int start, int end, int cost) : Start(start), End(end), Cost(cost) {}
};

vector<Node> edge;

bool bellmanFord(int s) {
    dist[s] = 0;
    int start, end, cost;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < edge.size(); j++) {
            start = edge[j].Start;
            end = edge[j].End;
            cost = edge[j].Cost;

            if (dist[start] == INF) {
                continue;
            }
            dist[end] = min(dist[end], dist[start] + cost);
        }
    }
    for (int j = 0; j < edge.size(); j++) {
        start = edge[j].Start;
        end = edge[j].End;
        cost = edge[j].Cost;
        
        if (dist[end] > dist[start] + cost) {
            return true;
        }
    }
    return false;
}

// 1865번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int TC, S, E, T;
    cin >> TC;
    while (TC-- > 0) {
        cin >> N >> M >> W;
        edge.clear();
        for (int i = 1; i < N; i++) {
            dist[i] = INF;
        }
        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            edge.push_back(Node(S, E, T));
            edge.push_back(Node(E, S, T));
        }
        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            edge.push_back(Node(S, E, -T));
        }
        if (bellmanFord(1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}