#include <bits/stdc++.h>

using namespace std;

#define ll long long

int count_bits(ll n) {
    int count = 0;
    while (n) {
        if (n&1LL)
            count++;
        n >>= 1;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, p, n, b, g, girlfriends[20], boys, girls;
    int resp;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> p >> n;
        resp = p;
        for (int j = 0; j < 20; j++)
            girlfriends[j] = 0LL;
        for (int j = 0; j < n; j++) {
            cin >> b >> g;
            b--;
            g--;
            girlfriends[b] |= (1LL << g);
        }
        for (boys = 0LL; boys < (1LL << p); boys++)
        {
            girls = (1LL << p) - 1LL;
            for (int j = 0; j < p; j++)
            {
                if (boys&(1LL << j))
                    girls &= girlfriends[j];
            }
            resp = max(resp, __builtin_popcount(boys)+__builtin_popcount(girls));
        }

        cout << resp << "\n";
    }

    return 0;
}