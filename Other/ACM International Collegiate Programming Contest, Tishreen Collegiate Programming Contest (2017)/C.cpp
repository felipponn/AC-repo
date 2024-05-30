#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, k, p, n, resp;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> k >> p >> n;
        resp = max(0LL, k - p)*n;

        cout << resp << "\n";
    }

    return 0;
}