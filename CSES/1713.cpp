// Counting Divisors
#include <bits/stdc++.h>
using namespace std;

int count_div(int n)
{
    int ret = 0;
    for (int i = 1; i * i <= n; i ++)
    {
        if (n % i == 0)
        {
            if (i * i == n) ret ++;
            else ret += 2;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i ++)
    {
        cin >> n;
        cout << count_div(n) << endl;
    }

    return 0;
}