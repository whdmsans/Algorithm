#include <bits/stdc++.h>

using namespace std;

int N, M, HN, CN, result;

int CA[13];
pair<int, int> HP[100];
pair<int, int> CP[13];

void func() {
    int cnt = 0;
    int ret = 0;
    for (int i = 0; i < HN; i++) {
        cnt = 100;
        for (int j = 0; j < M; j++) {
            cnt = min(cnt, abs(CP[CA[j] - 1].first - HP[i].first) + abs(CP[CA[j] - 1].second - HP[i].second));
        }
        ret += cnt;
    }
    result = min(ret, result);
}

void bp(int num, int cnt) {
    if (cnt == 0) {
        func();
        return;
    }
    for (int i = num + 1; i <= CN - cnt + 1; i++) {
        CA[M - cnt] = i;
        bp(i, cnt - 1);
    }
}

// 15686번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x;
    cin >> N >> M;
    CN = 0;
    HN = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> x;
            if (x == 2) {
                CP[CN++] = make_pair(i, j);
            } else if (x == 1) {
                HP[HN++] = make_pair(i, j);
            }
        }
    }
    result = 100 * 2 * N;
    bp(0, M);
    cout << result;
}
