#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, x, y, r, side_x, side_y;
    ll sum = 0LL;
    vector<pair<pair<int, int>, int>> v;

    cin >> n >> m >> s;

    for (int i = 0; i < s; i++) {
        cin >> x >> y >> r;
        v.push_back(make_pair(make_pair(x, y), r));
        side_x = 2*r + 1;
        side_y = 2*r + 1;
        if (x - r < 1) {
            side_x += x - r - 1;
        }
        if (x + r > n) {
            side_x -= x + r - n;
        }
        if (y - r < 1) {
            side_y += y - r - 1;
        }
        if (y + r > m) {
            side_y -= y + r - m;
        }
        sum += side_x * side_y;
    }

    double ans = (double)sum / (n*m);

    cout << floor(ans) << endl;


    return 0;
}