// Exponentiation
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1000000007;

ll power(ll a, ll b)
{
    if (b == 0LL) return 1LL;
    if (b == 1LL) return (a % MOD);
    if (b == 2LL) return ((a * a) % MOD);
    return (power(power(a % MOD, b / 2), 2LL) * power(a, b % 2LL) % MOD);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    
    int t;
    ll a, b;
    cin >> t;
    for (int i = 0; i < t; i ++)
    {
        cin >> a >> b;
        cout << power(a, b) << endl;
    }

    return 0;
}