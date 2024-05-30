#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define PB push_back

using namespace std;

int max(int a, int b, int c) {
    return max(max(abs(a), abs(b)), abs(c));
}

int min(int a, int b, int c) {
    return min(min(abs(a), abs(b)), abs(c));
}

int mid(int a, int b, int c) {
    return abs(a) + abs(b) + abs(c) - max(a, b, c) - min(a, b, c);
}

struct adesivo {
    int x;
    int y;
    int z;
    adesivo() {x=y=z=0;}
    adesivo(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    bool operator== (adesivo oth) const {
        return (x == oth.x && y == oth.y && z == oth.z);
    }
    bool operator!= (adesivo oth) const {
        return ((x != oth.x) || (y != oth.y) || (z != oth.z));
    }
};

void printStick(adesivo c) {
    cout << c.x << ", " << c.y << ", " << c.z << endl;
}

adesivo moveF (adesivo c) {
    if (c.z < 1)                return c;
    if (c.x == 0 && c.y == 0)   return c;
                                return adesivo(c.y, -c.x, c.z);
}

adesivo movef (adesivo c) {
    if (c.z < 1)                return c;
    if (c.x == 0 && c.y == 0)   return c;
                                return adesivo(-c.y, c.x, c.z);
}

adesivo moveB (adesivo c) {
    if (c.z > -1)               return c;
    if (c.x == 0 && c.y == 0)   return c;
                                return adesivo(-c.y, c.x, c.z);
}

adesivo moveb (adesivo c) {
    if (c.z > -1)               return c;
    if (c.x == 0 && c.y == 0)   return c;
                                return adesivo(c.y, -c.x, c.z);
}

adesivo moveR (adesivo c) {
    if (c.x < 1)                return c;
    if (c.y == 0 && c.z == 0)   return c;
                                return adesivo(c.x, c.z, -c.y);
}

adesivo mover (adesivo c) {
    if (c.x < 1)                return c;
    if (c.y == 0 && c.z == 0)   return c;
                                return adesivo(c.x, -c.z, c.y);
}

adesivo moveL (adesivo c) {
    if (c.x > -1)               return c;
    if (c.y == 0 && c.z == 0)   return c;
                                return adesivo(c.x, -c.z, c.y);
}

adesivo movel (adesivo c) {
    if (c.x > -1)               return c;
    if (c.y == 0 && c.z == 0)   return c;
                                return adesivo(c.x, c.z, -c.y);
}

adesivo moveU (adesivo c) {
    if (c.y < 1)                return c;
    if (c.z == 0 && c.x == 0)   return c;
                                return adesivo(-c.z, c.y, c.x);
}

adesivo moveu (adesivo c) {
    if (c.y < 1)                return c;
    if (c.z == 0 && c.x == 0)   return c;
                                return adesivo(c.z, c.y, -c.x);
}

adesivo moveD (adesivo c) {
    if (c.y > -1)               return c;
    if (c.z == 0 && c.x == 0)   return c;
                                return adesivo(c.z, c.y, -c.x);
}

adesivo moved (adesivo c) {
    if (c.y > -1)               return c;
    if (c.z == 0 && c.x == 0)   return c;
                                return adesivo(-c.z, c.y, c.x);
}

int repetitivo(string seq, adesivo orig) {
    adesivo copy = adesivo(orig.x, orig.y, orig.z);
    int ret = 0;
    do {
        ret++;
        for (auto op : seq) {
            switch (op) {
                case 'F':
                    copy = moveF(copy);
                    break;
                case 'f':
                    copy = movef(copy);
                    break;
                case 'B':
                    copy = moveB(copy);
                    break;
                case 'b':
                    copy = moveb(copy);
                    break;
                case 'U':
                    copy = moveU(copy);
                    break;
                case 'u':
                    copy = moveu(copy);
                    break;
                case 'D':
                    copy = moveD(copy);
                    break;
                case 'd':
                    copy = moved(copy);
                    break;
                case 'R':
                    copy = moveR(copy);
                    break;
                case 'r':
                    copy = mover(copy);
                    break;
                case 'L':
                    copy = moveL(copy);
                    break;
                case 'l':
                    copy = movel(copy);
                    break;
            }
        }
    } while (copy != orig);
    return ret;
}

int mdc(int a, int b) {
    if (a < b) return mdc(b, a);
    if (b == 0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b) {
    int MDC = mdc(a, b);
    return a*b/MDC;
}

int multi_mmc(vector<int> v) {
    int ret = mmc(v[0], v[1]);
    for (int i = 2; i < v.size(); i++) {
        ret = mmc(ret, v[i]);
    }
    return ret;
}

int main() {
    fast_io;
    string seq;
    vector<int> nums;
    while (cin >> seq) {
        for (int ix = -2; ix < 3; ix++) {
            for (int iy = -2; iy < 3; iy++) {
                for (int iz = -2; iz < 3; iz++) {
                    if (max(ix, iy, iz) < 2)
                        continue;
                    if (mid(ix, iy, iz) == 2)
                        continue;
                    nums.PB(repetitivo(seq, adesivo(ix, iy, iz)));
                }
            }
        }
        //cout << nums.size() << endl;
        //for (auto x: nums) cout << x << " ";
        //cout << endl;
        cout << multi_mmc(nums) << endl;
        nums.clear();
    }
    return 0;
}