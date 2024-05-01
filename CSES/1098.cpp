#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    
    int t, n;
    ll num, x;

    cin >> t;

    for (int i = 0; i < t; i ++)
    {
        cin >> n;
        x = 0LL;
        for (int j = 0; j < n; j ++)
        {
            cin >> num;
            if (num % 4)
                num = 2 * (num >> 2) + 1;
            else
                num = 2 * (num >> 2);
            x = x^(num);
        }
        cout << x << endl;
        if (x)
            cout << "first" << endl;
        else
            cout << "second" << endl;
    }

    return 0;
}