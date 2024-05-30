// 01/08/23 //
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

    int l;
    ll pot, b, di, check = 0LL;
    vector<int> d;

    cin >> b >> l;

    for (int i = 0; i < l; i++)
    {
        cin >> di;
        d.PB(di);
        if (i%2)
            check -= di;
        else
            check += di;
    }

    check %= (b+1);

    if (check == 0LL)
    {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    
    for (int i = 0; i < l; i++)
    {
        if (d[i] >= check)
        {
            cout << i+1 << " " << (d[i]-check) << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;

    return 0;
}