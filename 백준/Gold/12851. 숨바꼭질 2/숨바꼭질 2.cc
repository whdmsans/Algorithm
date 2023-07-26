#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

int N, K;
pair<int, int> dp[100001];

void func() {
    for (int i = 0; i < 100001; i++) {
        dp[i] = make_pair(INF, 0);
    }
    dp[N] = make_pair(0, 0);
    dp[K] = make_pair(abs(K - N), 0);
    priority_queue<pair<int, int>> pq;
    pq.push({0, N});
    int count, num;
    while (!pq.empty()) {
        count = -pq.top().first;
        num = pq.top().second;
        pq.pop();
        if (count > dp[K].first) {
            break;
        }
        if (dp[num].first == count) {
            dp[num].second++;
        } else if (dp[num].first > count) {
            dp[num] = make_pair(count, 1);
        }
        if (num == K) {
            continue;
        }
        if (num + 1 <= 100000 && dp[num + 1].first >= count + 1 && count + 1 <= dp[K].first) {
            pq.push({-(count + 1), num + 1});
        }
        if (num - 1 >= 0 && dp[num - 1].first >= count + 1 && count + 1 <= dp[K].first) {
            pq.push({-(count + 1), num - 1});
        }
        if (num * 2 <= 100000 && dp[num * 2].first >= count + 1 && count + 1 <= dp[K].first) {
            pq.push({-(count + 1), num * 2});
        }
    }
}

// 12851번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;
    func();
    cout << dp[K].first << "\n" << dp[K].second;
}