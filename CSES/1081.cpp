#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    
    int t, n, ret = 0, test = 1000000;
    cout << test << endl;
    vector<int> v;
    cin >> t;
    for (int i = 0; i < t; i ++)
    {
        cin >> n;
        v.push_back(n);
    }

    for (int i = 0; i < t; i ++)
        for (int j = i + 1; j < t; j ++)
            ret = max(ret, gcd(v[i], v[j]));
    
    cout << ret << endl;

    return 0;
}