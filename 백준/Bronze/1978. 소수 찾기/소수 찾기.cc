#include <iostream>

using namespace std;

int main()
{
    int n, t, c = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        for (int j =2; j < t; j++) {
            if (t % j == 0) {
                break;
            }
            if(j == t - 1) {
                c++;
            }
        }
        if ( t == 2) {
            c++;
        }
    }
    cout << c;
}