// 01/09/23 //
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cstring>
#include <stack>

using namespace std;

#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define ff first
#define ss second

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

const int INF  = 0x3f3f3f3f;
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

    int n, k, e, f;

    cin >> n >> k >> e;
    f = n - k - e;

    if (e != k && k != f && f != e)
        cout << 0 << endl;
    
    else if (e == k && k == f) {
        if (k == 1) cout << 2 << endl;
        else if (k == 2) cout << 3 << endl;
        else if (k == 3) cout << 3 << endl;
        else if (k == 4) cout << 2 << endl;
        else cout << 0 << endl;
    }

    else {
        int m = min(e, min(k, f)), rep = e + k + f - m - max(e,max(k,f));
        if (rep == 1) cout << 1 << endl;
        else if (rep == 2 && m == 1) cout << 2 << endl;
        else if (rep == 2) cout << 1 << endl;
        else if (rep == 3 && m < 3) cout << m % 3 << endl;
        else if (rep == 3) cout << 0 << endl;
        else if (rep == 4 && m < 4) cout << m % 2 << endl;
        else if (rep == 4) cout << 0 << endl;
        else cout << 0 << endl; 
    }

    return 0;
}