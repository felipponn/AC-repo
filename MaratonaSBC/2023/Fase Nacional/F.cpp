#include <bits/stdc++.h>
using namespace std;

#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)
#define FF first
#define SS second
#define PB push_back
#define endl "\n"

typedef long long int lli;

bool check_palindrome(lli N, lli b){
    vector<lli> v;
    while (N){
        v.PB(N%b);
        N = N / b;
    }
    int v_s = v.size();
    for (int i = 0; 2*i <= v_s; i++){
        if (v[i]!= v[v_s-1-i]) return false;
    }
    return true;
}

int main() {
    fast_io;
    lli n;
    cin >> n;
    vector<lli> v1, v2;
    for (lli i = 2LL; i*i <= n; i = i + 1LL) {
        if (check_palindrome(n, i)) v1.PB(i);
    }
    for (lli k = 1LL; k*k+k<n; k = k+1LL){
        if ((n-k)%k == 0) v2.PB((n-k)/k);
    }
    if (v1.size()==0 && v2.size()==0){
        cout << "*" << endl;
    }
    else{
        for(auto x:v1) cout << x << " ";
        for(int i = v2.size()-1; i >= 0; i--) cout << v2[i] << " ";
    }
    return 0;
}