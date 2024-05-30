#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k, v[3], resp;
    vector<int> a;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        a.clear();

        for (int j = 0; j < n; j++)
        {
            cin >> v[0] >> v[1] >> v[2];
            sort(v, v+3);
            a.push_back(v[0]);
            a.push_back(v[1]);
        }

        sort(a.begin(), a.end());

        resp = 0;
        for (int j = 0; j < k; j++)
            resp += a[j];

        cout << resp << "\n";
        
    }

    return 0;
}