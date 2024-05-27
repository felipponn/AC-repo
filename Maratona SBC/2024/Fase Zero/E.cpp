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
const int MAXN = 105;
const int MOD  = (1e9) + 7;

vector<int> are[MAXN];
int con[MAXN];
int sizes[MAXN];

vector<int> conecta(int n){
    int reg = 1;
    for (int i = 1; i <= n; i++) {
        if (!con[i]){
            con[i] = reg;
            sizes[reg] ++;
            reg++;
        }
        for (auto x: are[i]){
            con[x] = con[i];
            sizes[con[i]] ++;
        }
    }
    vector<int> ret;
    for (int i = 1; i < reg; i++) ret.PB(sizes[i]);
    ret.PB(1);
    sort(ret.begin(), ret.end());

    return ret;
}

void printa(vector<int> v) {
    int num = sz(v);
    cout << v[0];
    for (int i = 1; i < num; i++) cout << " " << v[i];
    cout << endl;
}

int main(){
    fast_io;
    
    int n, m, a, b;
    int prox_num_regs, min_num_regs = INF, sum_deg = 0, cnx_comps;
    vector<int> sz_regs, regs;

    cin >> n;
    
    for (int i = 0; i <= n; i++) {
        cin >> m;
        sum_deg += m;
        for(int i = 1; i <= n; i++)
            are[i].clear();
        memset(con, 0, sizeof(con));
        memset(sizes, 0, sizeof(sizes));
        for (int j = 0; j < m; j++) {
            cin >> a >> b;
            are[min(a, b)].push_back(max(a, b));
        }
        regs = conecta(n);
        prox_num_regs = sz(regs);
        if (prox_num_regs < min_num_regs) {
            min_num_regs = prox_num_regs;
            sz_regs = regs;
        }
        else if (prox_num_regs == min_num_regs) {
            if (regs < sz_regs)
                sz_regs = regs;
        }
    }
    
    sum_deg /= (n - 1);
    cnx_comps = (n + 1) - sum_deg;
    cout << cnx_comps << endl;
    
    if (cnx_comps == min_num_regs) {
        printa(sz_regs);
        return 0;
    }

    cout << sz_regs[1] + 1;
    for (int i = 2; i <= cnx_comps; i ++) {
        cout << " " << sz_regs[i];
    }
    cout << endl;

    return 0;
}