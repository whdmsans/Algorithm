#include <bits/stdc++.h>
#include <string>
using namespace std;

int word(string a, string b){ // 단어 정렬
    if(a.length() == b.length()) {
        return a < b;
    }
    else {
        return a.length() < b.length();
    }
}

string s[20000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s, s + n - m, word);

    //출력
    for(i = 0; i < n - m; i++) {
        if(i != 0 && s[i].compare(s[i - 1]) == 0){
            continue;
        }
        cout << s[i] << "\n";
    }
}