#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if (p1.second > p2.second) {
            return true;
        } else if (p1.second == p2.second) {
            if (p1.first > p2.first) {
                return true;
            }
            return false;
        }
        return false;
    }
};

int N, K;
int visited[100001] = {0};

int func() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(make_pair(N, 0));
    visited[N] = 1;
    int f, s;
    while (!pq.empty()) {
        f = pq.top().first;
        s = pq.top().second;
        pq.pop();

        if (f == K) {
            return s;
        }
        if (f * 2 <= 100000 && visited[f * 2] == 0) {
            visited[f * 2] = 1;
            pq.push(make_pair(f * 2, s));
        }
        if (f + 1 <= 100000 && visited[f + 1] == 0) {
            visited[f + 1] = 1;
            pq.push(make_pair(f + 1, s + 1));
        }
        if (f - 1 >= 0 && visited[f - 1] == 0) {
            visited[f - 1] = 1;
            pq.push(make_pair(f - 1, s + 1));
        }
    }
}

// 13549번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;
    cout << func();
}
