#include <bits/stdc++.h>
using namespace std;
#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)
#define endl "\n"

int main() {
    fast_io;
    int n,x, num_moves = 0, m, ret;
    vector<int> a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    b.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) b.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        if (i == 0) {
            c.push_back(b[i]);
        }
        else {
            c.push_back(b[i] - b[i - 1]);
        }
    }
    m = c.size();
    ret = 1;
    for (int i = m - 2; i >= 0; i--){
        if (c[i] > 1){
            if (!ret) {
                ret = 1;
            }
        }
        else {
            ret = 1 - ret;
        }
    }
    if (ret) cout << "Alicius\n";
    else cout << "Bobius\n";
    return 0;
}