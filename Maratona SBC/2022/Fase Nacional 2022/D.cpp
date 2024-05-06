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

    int n, h, w;
    char rw, rh;

    cin >> n >> h >> w;

    for (int i = 0; i < n; i ++) {
        cin >> rw >> rh;
        if (rw == 'Y' || w == 0) {
            h --;
            w ++;
            cout << "Y ";
        }
        else cout << "N ";
        if (rh == 'Y' || h == 0) {
            h ++;
            w --;
            cout << "Y" << endl; 
        }
        else cout << "N" << endl;
    }

    return 0;
}