// Exponentiation II
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1000000007;

ll power(ll a, ll b, ll mod)
{
    if (b == 0LL) return 1LL;
    if (b == 1LL) return (a % mod);
    if (b == 2LL) return ((a * a) % mod);
    return (power(power(a, b / 2, mod), 2LL, mod) * power(a, b % 2LL, mod) % mod);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    
    int t;
    ll a, b, c;
    cin >> t;
    for (int i = 0; i < t; i ++)
    {
        cin >> a >> b >> c;
        cout << power(a, power(b, c, MOD - 1LL), MOD) << endl;
    }

    return 0;
}