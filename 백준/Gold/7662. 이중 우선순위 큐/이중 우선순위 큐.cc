#include <bits/stdc++.h>

using namespace std;

// 7662번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, k, n;
    char c;
    multiset<int> ms;
    cin >> T;
    while (T-- > 0) {
        ms.clear();
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> c >> n;
            if (c == 'I') {
                ms.insert(n);
            } else if (c == 'D') {
                if (ms.empty()) {
                    continue;
                } else if (n == 1) {
                    auto e = ms.end();
                    ms.erase(--e);
                } else if (n == -1) {
                    ms.erase(ms.begin());
                }
            }
        }
        if (ms.empty()) {
            cout << "EMPTY\n";
        } else {
            auto e = ms.end();
            e--;
            cout << *e << " " << *ms.begin() << "\n";
        }
    }
}
