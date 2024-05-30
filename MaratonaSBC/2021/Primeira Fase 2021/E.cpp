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

    int n;
    cin >> n;

    int crr_time=0, op=-1;
    queue<int> up, down;

    for(int i=0; i<n; i++){
        int t, d;
        cin >> t >> d;

        if(i==0) op = d;

        if(d==0){
            up.push(t);
        }
        else{
            down.push(t);
        }
    }

    // 0 == up
    // 1 == down

    while(n--){
        if(up.empty()){ // vai sempre descer 1
            if(op==0){
                crr_time = max(crr_time+10, down.front()+10);
            }   
            else{
                crr_time = down.front()+10;
            }

            op = 1;
            down.pop();
        }
        else if(down.empty()){ // vai sempre subir 0
            if(op==1){
                crr_time = max(crr_time+10, up.front()+10);
            }   
            else{
                crr_time = up.front()+10;
            }

            op = 0;
            up.pop();
        }
        else if(op==0 && up.front()<crr_time){
            crr_time = up.front()+10;
            up.pop();
        }
        else if(op==1 && down.front()<crr_time){
            crr_time = down.front()+10;
            down.pop();
        }
        else if(up.front()<down.front()){
            crr_time = up.front() + 10;
            op = 0;
            up.pop();
        }
        else{
            crr_time = down.front() + 10;
            op = 1;
            down.pop();
        }
    }

    cout << crr_time << endl;

    return 0;
}