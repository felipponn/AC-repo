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
const int MAXN = (1e3) + 5;
const int MOD  = (1e9) + 7;

int pref[2*MAXN*MAXN];
int apar[MAXN];
int main(){
    fast_io;
    int n, m;
    string s;
    cin >> n >> m >> s;
    pref[0] = s[0] == '1' ? 1 : 0;
    for (int i = 1; i < n*m; i++) {
        if (s[i] == '1') {
            pref[i] = pref[i - 1] + 1;
        }
        else pref[i] = pref[i - 1];
    }
    for (int i = n*m; i < 2*n*m; i++) {
        if (s[i - n*m] == '1') {
            pref[i] = pref[i - 1] + 1;
        }
        else pref[i] = pref[i - 1];
    }

    // for (int i = 0; i < 2*n*m; i++)
    //     cout << pref[i] << endl;

    bool fail_flag = 0;

    for (int i = 0; i < m; i++) {
        memset(apar, 0, sizeof(apar));
        for (int j = i; j < i+n*m; j += m) {
            // cout << pref[j+m] - pref[j] << endl;
            if (apar[pref[j+m] - pref[j]]) {
                fail_flag = 1;
                break; 
            }
            apar[pref[j+m] - pref[j]] = 1;
        }
        // cout << endl;
        if (fail_flag)
            break;
    }

    if (fail_flag)
        cout << "N\n";
    
    else cout << "S\n";

    return 0;
}