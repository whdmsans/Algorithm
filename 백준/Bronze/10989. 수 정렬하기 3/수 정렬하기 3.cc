#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    int t[10000] = { 0,};
    int a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        t[a -1]++;
    }
    for(int i = 0; i < 10000; i++) {
        for(int j = 0; j < t[i]; j++){
            cout << i + 1 << "\n";
        }
    }
}