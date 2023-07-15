#include <bits/stdc++.h>

using namespace std;

int person[51] = {0};
vector<int> PR[51];

void dfs(int x) {
    for (int p: PR[x]) {
        if (person[p] == 1) {
            continue;
        }
        person[p] = 1;
        dfs(p);
    }
}

// 1043번
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, p, result;

    int party_personnel[51];
    int party[51][50];

    cin >> N >> M;

    cin >> party_personnel[0];
    for (int i = 0; i < party_personnel[0]; i++) {
        cin >> p;
        person[p] = 1;
        party[0][i] = p;
    }
    for (int i = 0; i < party_personnel[0]; i++) {
        for (int j = 0; j < party_personnel[0]; j++) {
            if (i == j) {
                continue;
            }
            PR[party[0][i]].push_back(party[0][j]);
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> party_personnel[i];
        for (int j = 0; j < party_personnel[i]; j++) {
            cin >> p;
            party[i][j] = p;
        }
        for (int j = 0; j < party_personnel[i]; j++) {
            for (int k = 0; k < party_personnel[i]; k++) {
                if (j == k) {
                    continue;
                }
                PR[party[i][j]].push_back(party[i][k]);
            }
        }
    }

    for (int i = 0; i < party_personnel[0]; i++) {
        dfs(party[0][i]);
    }

    result = M;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < party_personnel[i]; j++) {
            if (person[party[i][j]] == 1) {
                result--;
                break;
            }
        }
    }

    cout << result;
}
