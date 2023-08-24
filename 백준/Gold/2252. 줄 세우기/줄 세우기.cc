#include <bits/stdc++.h>

using namespace std;

int idg[32001] = {0};
vector<int> v[32001];

// 2252번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, A, B;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        idg[B]++;
        v[A].push_back(B);
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (idg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        A = q.front();
        q.pop();
        cout << A << " ";
        for (int i = 0; i < v[A].size(); i++) {
            idg[v[A][i]]--;
            if (idg[v[A][i]] == 0) {
                q.push(v[A][i]);
            }
        }
    }
    return 0;
}