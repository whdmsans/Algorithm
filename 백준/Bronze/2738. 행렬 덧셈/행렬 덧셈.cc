#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int N, M, i, a;
    cin >> N >> M;
    int** A = new int* [N];
    for (i = 0; i < N; i++) {
        A[i] = new int[M];
    }

    for (i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    for (i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a;
            A[i][j] += a;
        }
    }
    for (i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }


    for (i = 0; i < N; i++) {
        delete[] A[i];
    }
    delete[] A;
}