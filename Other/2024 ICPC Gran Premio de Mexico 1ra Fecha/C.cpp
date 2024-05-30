#include <bits/stdc++.h>
using namespace std;
#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)
#define endl "\n"
int main() {
    fast_io;
    int A[3], a[3], ret = 0;
    cin >> A[0] >> A[1] >> A[2];
    cin >> a[0] >> a[1] >> a[2];
 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            for (int k = 0; k < 3; k++) {
                if ((k == j) || (k == i)) continue;
                if ((A[i]/a[0]) * (A[j]/a[1]) * (A[k]/a[2]) > ret) {
                    ret = (A[i]/a[0]) * (A[j]/a[1]) * (A[k]/a[2]);
                }
            }
        }
    }
    cout << ret << endl;
 
    return 0;
}