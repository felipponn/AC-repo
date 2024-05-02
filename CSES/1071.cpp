// Number Spiral
#include <iostream>
#include <math.h>

#define ll long long

using namespace std;

int main ()
{
    int t;
    ll y, x, M, dist, ret;

    cin >> t;

    for (int i = 0; i < t; i ++)
    {
        cin >> y >> x;
        M = max(y, x);

        if (M % 2)
        {
            dist = abs(y - 1) + abs(x - M);
            ret = M * M - dist;
        }

        else
        {
            dist = abs(x - 1) + abs(y - M);
            ret = M * M - dist;
        }

        cout << ret << endl;
    }

    return 0;
}