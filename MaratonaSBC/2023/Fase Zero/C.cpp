#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k, q;

    cin >> n >> k;
    
    
    for (ll i = 2*n; i > 0; i--) {
        q = i*i;
        if (abs(q - k) % (2*n + 1) == 0 && q != k) {
            cout << q << endl;
            break;
        }
    }

    return 0;
}