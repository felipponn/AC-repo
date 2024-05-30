#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)
#define ll long long
#define FF first
#define SS second
#define PB push_back
#define MAXN 3005

typedef pair<int, int> pii;

int main() {
    fast_io;
    int n;
    cin >> n;
    vector<int> v (3*n);
    for (int i = 0; i < 3*n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    bool a = false;
    for (int i = 0; i < n; i++){
        if (v[3*i + 2] != v[3*i]) a = true;
    }
    if (a) cout << "Y" << endl;
    else cout << "N" << endl;

    
    return 0;
}