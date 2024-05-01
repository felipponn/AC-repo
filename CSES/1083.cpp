#include <iostream>

using namespace std;

int main()
{

    long long SUM = 0LL, m, n;

    cin >> n;

    for (int i = 1; i < n; i ++)
    {
        cin >> m;
        SUM += m;
    }

    m = n * (n + 1)/2 - SUM;

    cout << m << endl;

    return 0;
}