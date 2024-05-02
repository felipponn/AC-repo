// Increasing Array
#include <iostream>

#define ll long long

using namespace std;

int main ()
{
    int n;
    ll atu, prev, ret = 0;

    cin >> n >> prev;

    for (int i = 1; i < n; i ++)
    {
        cin >> atu;

        if (atu < prev)
        {
            ret += (prev - atu);
            atu = prev;
        }

        prev = atu;
    }

    cout << ret << endl;

    return 0;
}