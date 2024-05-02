// Two Knights
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAXN 10005
#define endl "\n"

ll choose2(int n) {
    if (n < 2) return 0LL;
    return n * (n - 1) / 2;
}

ll solve(int n) {
    if (n == 1)
        return 0LL;
    if (n == 2)
        return 6LL;
    if (n == 3)
        return 28LL;
    if (n == 4)
        return 96LL;
    ll tab = n * n;
    ll ret = 0LL;
    ret += ((n - 4) * (n - 4)) * 
           (tab - 9);
    ret += (4 * (n - 4)) *
           (tab - 7);
    ret += (4 * (n - 4)) *
           (tab - 5);
    ret += (4) * (tab - 5);
    ret += (8) * (tab - 4);
    ret += (4) * (tab - 3);
    return ret/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << solve(i) << endl;
    }
}