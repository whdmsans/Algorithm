#include <bits/stdc++.h>

using namespace std;

string bfs(int A, int B) {
    int visited[10000] = {0};
    string s;
    queue<pair<int, string>> q;
    q.push(make_pair(A, ""));
    visited[A] = 1;
    while (!q.empty()) {
        A = q.front().first;
        s = q.front().second;
        q.pop();
        if (B == A) {
            return s;
        }
        if (visited[(2 * A) % 10000] == 0) {
            visited[(2 * A) % 10000] = 1;
            q.push(make_pair((2 * A) % 10000, s + "D"));
        }
        if (visited[(A + 9999) % 10000] == 0) {
            visited[(A + 9999) % 10000] = 1;
            q.push(make_pair((A + 9999) % 10000, s + "S"));
        }
        if (visited[((A / 1000) + (A * 10)) % 10000] == 0) {
            visited[((A / 1000) + (A * 10)) % 10000] = 1;
            q.push(make_pair(((A / 1000) + (A * 10)) % 10000, s + "L"));
        }
        if (visited[(A % 10) * 1000 + A / 10] == 0) {
            visited[(A % 10) * 1000 + A / 10] = 1;
            q.push(make_pair((A % 10) * 1000 + A / 10, s + "R"));
        }
    }
}

// 9019번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    int A, B;
    cin >> T;
    while (T-- > 0) {
        cin >> A >> B;
        cout << bfs(A, B) << "\n";
    }
}
