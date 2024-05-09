/*
2024-03-19 
Problem: Odd Sum
Complexity: O(1)
Difficulty: 1
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
const  ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = (2e5) + 5;
const int MOD  = (1e9) + 7;

ll exp(ll a, ll b, ll m=MOD){ // 0^0 = 1
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

int main(){
    fast_io;

    int t, a, b, ti = 1;
    cin >> t;

    while(ti <= t) {
        cout << "Case " << ti << ": ";
        cin >> a >> b;
        if (a % 2 == 0) a++;
        if (b % 2 == 0) b--;
        if (a > b) cout << 0 << endl;
        else cout << (a + b) * ((b - a) / 2 + 1) / 2 << endl;
        ti++;
    }

    return 0;
}