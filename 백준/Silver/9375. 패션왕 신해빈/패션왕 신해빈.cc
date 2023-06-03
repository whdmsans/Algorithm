#include <bits/stdc++.h>

using namespace std;

// 9275번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t, n, sum;
    cin >> t;
    string s, s1;
    map<string, int> map1;
    map<string, int>::iterator temp;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> s >> s1;
            temp = map1.find(s1);
            if (temp == map1.end()) {
                map1.insert({s1, 1});
                continue;
            }
            temp->second++;
        }
        sum = 1;
        for (temp = map1.begin(); temp != map1.end(); temp++) {
            sum *= (temp->second + 1);
        }
        map1.clear();
        cout << sum - 1 << "\n";
    }
}