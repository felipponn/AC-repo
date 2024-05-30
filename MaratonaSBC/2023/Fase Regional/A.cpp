#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define EB emplace_back
#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)
#define endl "\n"

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int main ()
{
    fast_io;
    int n, h, x, count=0;
    cin >> n >> h;
    for (int i=0; i<n; i++)
    {
        cin  >> x;
        if (x<= h) count++;
    }
    cout << count << endl;

    return 0;
}