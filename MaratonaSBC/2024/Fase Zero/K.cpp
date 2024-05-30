#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define EB emplace_back
#define FF first
#define SS second
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<ll> poly;

ll mod[3] = {998244353LL, 1004535809LL, 1092616193LL};
ll root[3] = {102292LL, 12289LL, 23747LL};
ll root_1[3] = {116744195LL, 313564925LL, 642907570LL};
ll root_pw[3] = {1LL << 23, 1LL << 21, 1LL << 21};

const ll MAXN = 2000005LL;
const int MAXK = 200005;

ll check[MAXN];
vector<ll> primes = {0};

void build_primes() {
    memset(check, 1LL, sizeof(check));
    check[0] = 0LL;
    check[1] = 0LL;
    ll cnt = 1LL;
    for (int i = 2; i < MAXN; i ++) {
        if (check[i]) {
            primes.PB(i);
            check[i] = cnt++;
            for (int j = 2 * i; j < MAXN; j += i)
                check[j] = 0LL;
        }
    }
}

ll modInv(ll b, ll m) {
    ll e = m - 2;
    ll res = 1;
    while (e) {
        if (e & 1) {
            res = (res * b) % m;
        }
        e /= 2;
        b = (b * b) % m;
    }
    return res;
}

poly normalize(poly a, int id) {
    int m = mod[id];
    int n = sz(a);
    poly b(n);
    for (int i = 0; i < n; i++) {
        b[i] = (((a[i] % m) + m) % m);
    }
    return b;
}

void ntt(poly &a, bool invert, int id) {
    ll n = (ll)a.size(), m = mod[id];
    for (ll i = 1, j = 0; i < n; ++i) {
        ll bit = n >> 1;
        for (; j >= bit; bit >>= 1) {
            j -= bit;
        }
        j += bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    for (ll len = 2, wlen; len <= n; len <<= 1) {
        wlen = invert ? root_1[id] : root[id];
        for (ll i = len; i < root_pw[id]; i <<= 1) {
            wlen = (wlen * wlen) % m;
        }
        for (ll i = 0; i < n; i += len) {
            ll w = 1;
            for (ll j = 0; j < len / 2; j++) {
                ll u = a[i + j], v = (a[i + j + len / 2] * w) % m;
                a[i + j] = (u + v) % m;
                a[i + j + len / 2] = (u - v + m) % m;
                w = (w * wlen) % m;
            }
        }
    }
    if (invert) {
        ll inv = modInv(n, m);
        for (ll i = 0; i < n; i++) {
            a[i] = (a[i] * inv) % m;
        }
    }
}

poly convolution(poly a, poly b, int id = 0) {
    a = normalize(a, id);
    b = normalize(b, id);
    int ans_size = sz(a) + sz(b) - 1;
    ll n = 1LL, len = (1LL + a.size() + b.size());
    while (n < len) {
        n *= 2;
    }
    a.resize(n);
    b.resize(n);
    ntt(a, 0, id);
    ntt(b, 0, id);
    poly answer(n);
    for (ll i = 0; i < n; i++) {
        answer[i] = (a[i] * b[i]);
    }
    ntt(answer, 1, id);
    answer.resize(ans_size);
    return answer;
}

void printa(poly a) {
    int d = sz(a);
    cout << a[0];
    for (int i = 1; i < d; i++) cout << " " << a[i];
    cout << endl;
}

int t, k;
poly seg[4 * MAXK];

void build(int idx, int l, int r) {
    if (l == r) {
        poly a(2);
        a[1] = 1LL;
        a[0] = primes[l] - 1LL;
        seg[idx] = a;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);
    seg[idx] = convolution(seg[2 * idx + 1], seg[2 * idx + 2], 0);
} 

int main() {
    fast_io;
    build_primes();

    cin >> t >> k;
    
    if (k > check[t]) {
        cout << 0 << endl;
        return 0;
    }

    build(0, 1, check[t] - 1);

    // printa(seg[0]);

    ll ret = seg[0][k - 1];

    for (int i = 1; i < check[t]; i ++) {
        ret *= modInv(primes[i], mod[0]);
        ret %= mod[0];
    }

    ret *= modInv(t, mod[0]);
    ret %= mod[0];

    cout << ret << endl;

    return 0;
}