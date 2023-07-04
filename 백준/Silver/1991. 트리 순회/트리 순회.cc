#include <bits/stdc++.h>

using namespace std;

int g[26][2];
char c[26];

void preoderTraversal(int n) {
    cout << c[n];
    if (g[n][0] != -1) {
        preoderTraversal(g[n][0]);
    }
    if (g[n][1] != -1) {
        preoderTraversal(g[n][1]);
    }
}

void inorderTraversal(int n) {
    if (g[n][0] != -1) {
        inorderTraversal(g[n][0]);
    }
    cout << c[n];
    if (g[n][1] != -1) {
        inorderTraversal(g[n][1]);
    }
}

void postorderTraversal(int n) {
    if (g[n][0] != -1) {
        postorderTraversal(g[n][0]);
    }
    if (g[n][1] != -1) {
        postorderTraversal(g[n][1]);
    }
    cout << c[n];
}

// 1991번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 26; i++) {
        c[i] = 'A' + i;
    }
    int N;
    cin >> N;
    char n, l, r;
    for (int i = 0; i < N; i++) {
        cin >> n >> l >> r;
        if (l != '.') { g[n - 'A'][0] = l - 'A'; }
        else { g[n - 'A'][0] = -1; }
        if (r != '.') { g[n - 'A'][1] = r - 'A'; }
        else { g[n - 'A'][1] = -1; }
    }
    preoderTraversal(0);
    cout << "\n";
    inorderTraversal(0);
    cout << "\n";
    postorderTraversal(0);
}
