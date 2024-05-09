/*
2024-03-19 
Problem: Erasing Zeroes
Complexity: O(n)
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

    int t, ret;
    string strA;
    bool preFlag[100];
    bool sufFlag[100];
    bool preOneflag, sufOneflag;

    cin >> t;

    while(t--) {
        cin >> strA;
        for (int i = 0; i < 100; i++){
            preFlag[i] = false;
            sufFlag[i] = false;
        }

        preOneflag = false;
        sufOneflag = false;

        for (int i = 0; i < strA.size(); i++){
            if (strA[i] == '1'){
                preOneflag = true;
            }
            if (strA[strA.size() - i - 1] == '1'){
                sufOneflag = true;
            }
            if (strA[i] == '0' && preOneflag){
                preFlag[i] = true;
            }
            if (strA[strA.size() - i - 1] == '0' && sufOneflag){
                sufFlag[strA.size() - i - 1] = true;
            }
        }

        ret = 0;
        for (int i = 0; i < strA.size(); i++){
            if (preFlag[i] && sufFlag[i]){
                ret++;
            }
        }

        cout << ret << endl;
    }

    return 0;
}