#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)
#define endl "\n"

#define ll long long int
const int MAXN = 1e6+5;
ll MOD = 1e9+7;
ll ans[MAXN];

int main() {
    fast_io;
    int n;
    cin>>n;
    
    ans[1] = 0;
    ans[2] = 0;
    ans[3] = 1;
    ans[4] = 1;
    ans[5] = 2;
    ans[6] = 3;
    ans[7] = 5;
    ans[8] = 6;
    ans[9] = 9;
    ans[10] = 11;
    ans[11] = 15;
    ans[12] = 18;
    ans[13] = 23;
    ans[14] = 27;
    if (n < 15) {cout<<ans[n]<<endl;
    return 0;}
    ll diff = 3;
    ll alt_diff = -2;
    ll div = 7;
    for(int i=15; i<=n; i++){
        ans[i] = (ans[i-1] + div) % MOD;
        if (i%2LL) {
            div += (alt_diff + ((i%12LL) == 5LL));
            div += MOD;
            div %= MOD;
            if ((i%12LL) == 1LL) alt_diff--;
        }
        else {
            div += (diff);
            div %= MOD;
            if ((i%6LL) == 0LL) diff++;
            diff %= MOD;
        }
        div %= MOD;
        alt_diff %= MOD;
        diff %= MOD;
    }
    cout<<ans[n]<<endl;

    return 0;
}