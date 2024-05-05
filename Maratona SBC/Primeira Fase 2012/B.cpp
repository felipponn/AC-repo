#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define PB push_back
using namespace std;
#define EPS 1e-9

struct point {
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
    double norm() {return hypot(x, y);}
    bool operator== (point oth) const {
        return (fabs(x - oth.x) < EPS && (fabs(y - oth.y) < EPS));
    }
    point operator+ (point oth) const {
        return point(x+oth.x, y+oth.y);
    }
    point operator- (point oth) const {
        return point(x-oth.x, y-oth.y);
    }
    point operator* (double k) const {
        return point(x*k, y*k);
    }
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double inner(point p1, point p2) {
    return p1.x*p2.x + p1.y*p2.y;
}

point closestToLineSegment(point p, point a, point b) {
    double u = inner(p-a, b-a)/inner(b-a,b-a);
    if (u < 0.0) return a;
    if (u > 1.0) return b;
    return a + ((b-a)*u);
}

int main() {
    fast_io;
    cout.setf(ios_base::fixed);
    cout.precision(2);
    int n, h, l, yi, xf, yf;
    double ret;
    int flag_D;
    point Pi, Pf, last_Pi, last_Pf;
    while (cin >> n) {
        cin >> l >> h;
        point IE = point(0.0, 0.0);
        point SE = point(0.0, h);
        point ID = point(l, 0.0);
        point SD = point(l, h);
        cin >> yi >> xf >> yf;
        Pi = point(0, yi);
        Pf = point(xf, yf);
        ret = dist(Pf, closestToLineSegment(Pf, ID, SD));
        flag_D = 1;
        for (int i = 1; i < n; i++) {
            last_Pi = Pi;
            last_Pf = Pf;
            cin >> yi >> xf >> yf;
            if (flag_D)
                Pi = point(l, yi);
            else 
                Pi = point(0, yi);
            Pf = point(xf, yf);
            ret = min(ret, dist(last_Pf, closestToLineSegment(last_Pf, Pi, Pf)));
            if (flag_D)
                ret = min(ret, dist(Pf, closestToLineSegment(Pf, IE, SE)));
            else
                ret = min(ret, dist(Pf, closestToLineSegment(Pf, ID, SD)));
            flag_D = 1 - flag_D;
        }
        cout << ret << endl;
    }
    
    return 0;
}