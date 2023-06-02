#include <bits/stdc++.h>

using namespace std;

struct p {
    int num, idx;
};

// 11003번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, L, t;
    cin >> N >> L;
    deque<p> dq;
    p p1;

    for (int i = 1; i <= N; i++) {
        t = i - L + 1;
        cin >> p1.num;
        p1.idx = i;

        while (!dq.empty() && dq.front().idx < t) {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back().num > p1.num) {
            dq.pop_back();
        }
        dq.push_back(p1);
        cout << dq.front().num << " ";
    }
}
