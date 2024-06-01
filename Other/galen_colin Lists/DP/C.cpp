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

int n, p, bit_mask, ret;
string vit;
int vitamin[10];

int main(){
    fast_io;
    memset(vitamin, -1, sizeof(vitamin));

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> p >> vit;
        bit_mask = 0;
        for (char c: vit) {
            if (c == 'A')
                bit_mask |= 1;
            if (c == 'B')
                bit_mask |= 2;
            if (c == 'C')
                bit_mask |= 4;
        }
        
        if (vitamin[bit_mask] == -1)
            vitamin[bit_mask] = p;
        
        else
            vitamin[bit_mask] = min(p, vitamin[bit_mask]);
    }

    ret = -1;

    if (vitamin[7] != -1) ret = vitamin[7];

    if ((vitamin[3] != -1) && (vitamin[6] != -1)) {
        p = vitamin[3] + vitamin[6];
        if (ret == -1) ret = p;
        else ret = min(ret, p);
    }

    if ((vitamin[3] != -1) && (vitamin[5] != -1)) {
        p = vitamin[3] + vitamin[5];
        if (ret == -1) ret = p;
        else ret = min(ret, p);
    }

    if ((vitamin[5] != -1) && (vitamin[6] != -1)) {
        p = vitamin[5] + vitamin[6];
        if (ret == -1) ret = p;
        else ret = min(ret, p);
    }

    if ((vitamin[1] != -1) && (vitamin[2] != -1) && (vitamin[4] != -1)) {
        p = vitamin[1] + vitamin[2] + vitamin[4];
        if (ret == -1) ret = p;
        else ret = min(ret, p);
    }

    if ((vitamin[1] != -1) && (vitamin[6] != -1)) {
        p = vitamin[1] + vitamin[6];
        if (ret == -1) ret = p;
        else ret = min(ret, p);
    }

    if ((vitamin[2] != -1) && (vitamin[5] != -1)) {
        p = vitamin[2] + vitamin[5];
        if (ret == -1) ret = p;
        else ret = min(ret, p);
    }

    if ((vitamin[4] != -1) && (vitamin[3] != -1)) {
        p = vitamin[4] + vitamin[3];
        if (ret == -1) ret = p;
        else ret = min(ret, p);
    }

    cout << ret << endl;

    return 0;
}