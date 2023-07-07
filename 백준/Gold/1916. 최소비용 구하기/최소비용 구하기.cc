#include <bits/stdc++.h>

using namespace std;

int N, M, A, B;
vector<pair<int, int>> busLine[1001];
int visited[1001] = {0};
int dp[1001];

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second > p2.second) {
            return true;
        }
        return false;
    }
};

void func(int x) {
    int num, cost;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(x, 0));
    while (!pq.empty()) {
        num = pq.top().first;
        cost = pq.top().second;
        pq.pop();
        while (!pq.empty() && visited[num] != 0) {
            num = pq.top().first;
            cost = pq.top().second;
            pq.pop();
        }
        if (visited[num] != 0) {
            break;
        }
        visited[num] = 1;
        dp[num] = cost;
        for (pair<int, int> pair1: busLine[num]) {
            if (visited[pair1.first] != 0) {
                continue;
            }
            pq.push(make_pair(pair1.first, pair1.second + cost));
        }
    }
}

// 1916번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int cost;
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> cost;
        busLine[A].push_back(make_pair(B, cost));
    }
    cin >> A >> B;
    func(A);
    cout << dp[B];
}
