#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    
    int n, ret = 1;
    ll num;
    vector<ll> v;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i < n; i ++)
    {
        if (v[i] != v[i - 1])
            ret ++;
    }

    cout << ret << endl;

    return 0;
}