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
const int MAXN = 520;
const int MOD  = (1e9) + 7;

int N, M, k, l;

bool tabuleiro[MAXN][MAXN];

pii delta[] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main(){
    fast_io;
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) tabuleiro[i][j] = 0;
    char pos;
    cin >> N >> M >> k >> l;
    k--;l--;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> pos;
            if (pos == '*'){ tabuleiro[i][j] = 1;}
        }
    }

    int max_ret = -1;
    int max_i = 0;
    int max_j = 0;
    int a, b, c;

    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++) {
            if (tabuleiro[i][j]) continue;
            c = 0;
            for (auto x: delta) {
                a = x.FF;
                b = x.SS;
                // if (i == 3 && j == 3) cout << i+a*k << " " << j+b*l << endl;
                if ((i + a*k > 0) && (i + a*k <= N)) {
                    if ((j + b*l > 0) && (j + b*l <= M)) {
                        if (tabuleiro[i+a*k][j+b*l]) c++;
                    }
                }
                if ((i + a*l > 0) && (i + a*l <= N)) {
                    if ((j + b*k > 0) && (j + b*k <= M)) {
                        if (tabuleiro[i+a*l][j+b*k]) c++;
                    }
                }
            }
            if (c > max_ret) {
                max_ret = c;
                max_i = i;
                max_j = j;
            }
            // if (i == 3 && j == 3) cout << c << endl;
        }
    }

    cout << max_i << " " << max_j << "\n";

    return 0;
}