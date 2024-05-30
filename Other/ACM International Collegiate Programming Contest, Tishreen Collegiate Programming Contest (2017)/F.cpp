#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, sum, x;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        sum = 0LL;
        for (int j = 1; j < n; j++)
        {
            cin >> x;
            sum += x;
        }
        cout << (n*(n + 1LL))/2LL - sum << "\n";
    }

    return 0;
}