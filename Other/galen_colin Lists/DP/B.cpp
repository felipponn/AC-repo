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

int n, k, last;
char c;
char given[MAXN];
bool alphabet[27];
ll ret;

int main(){
    fast_io;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> given[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> c;
        alphabet[c - 'a'] = 1;
    }

    if (alphabet[given[0] - 'a']) {
        last = 0;
        ret = 1LL;
    }
    else {
        ret = 0LL;
        last = -1;
    }

    for (int i = 1; i < n; ++i) {
        if (alphabet[given[i] - 'a']) {
            if (last == -1) {
                ret += 1LL;
                last = i;
            }
            else {
                ret += (i - last + 1);
            }
        }
        else {
            last = -1;
        }
    }

    cout << ret << endl;

    return 0;
}