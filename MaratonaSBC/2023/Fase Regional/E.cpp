#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)
const int MAXN = 1e6 + 6;

int freq[MAXN];

int sum_digits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += (n % 10);
        n /= 10;
    }
    return cnt;
}

int main ()
{
    fast_io;
    int n, k, f;

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> f;
        freq[f]++;
    }

    for (int i = MAXN - 1; i > 0; i--)
    {
        while (k > 0 && freq[i] > 0)
        {
            if (freq[i] < k)
            {
                k -= freq[i];
                freq[i - sum_digits(i)] += freq[i];
                freq[i] = 0;
                continue;
            }
            freq[i]--;
            freq[i - sum_digits(i)]++;
            k--;
        }
        if (k == 0)
        {
            cout << sum_digits(i) << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}