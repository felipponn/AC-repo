#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PB push_back
#define EB emplace_back
#define fast_io cin.tie(0);ios_base::sync_with_stdio(0)

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

struct pt{
    ll id, x, y;
};

bool cmp(pt a, pt b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp1(pt a, pt b){
    return a.id < b.id;
}

bool cw(pt a, pt b, pt c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0LL;
}

bool ccw(pt a, pt b, pt c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0LL;
}

void convex_hull(vector<pt> &a){
    if (a.size()==1) return;

    sort(a.begin(),a.end(),&cmp);
    pt p1 =a[0], p2=a.back();
    vector<pt> up, down;
    up.PB(p1);
    down.PB(p1);
    for (int i=1; i<(int)a.size();i++)
    {
        if(i==a.size()-1|| cw(p1, a[i], p2)){
            while(up.size()>=2 && !cw(up[up.size()-2],up[up.size()-1],a[i]))
                up.pop_back();
            up.PB(a[i]);
        }
        if (i==a.size() -1 || ccw(p1,a[i],p2)){
            while(down.size()>=2 && !ccw(down[down.size()-2],down[down.size()-1],a[i]))
                down.pop_back();
            down.PB(a[i]);
        }
    }

    a.clear();
    for (int i=0; i<(int)up.size();i++)
        a.PB(up[i]);
    for(int i=down.size()-2;i>0;i--)
        a.PB(down[i]);
}

int main ()
{
    fast_io;
    ll n, x, y;
    vector<pt> v;

    cin>>n;
    for(int i =0; i< n; i++){
        cin>>x>>y;
        pt a = {i+1, x,y};
        v.PB(a);
    }

    convex_hull(v);
    sort(v.begin(),v.end(), &cmp1);

    for (int i = 0; i < v.size();i++){
        if (i==0 || v[i].id != v[i-1].id)
        cout << v[i].id << " ";
    }
    cout << endl;


    return 0;
}