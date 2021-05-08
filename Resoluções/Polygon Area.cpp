#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;

struct PT {
    ll x, y;
    PT (ll x = 0, ll y = 0) : x(x), y(y) {}
    PT operator- (const PT& o) const { return {x - o.x, y - o.y}; }

    // vector space
    PT operator+ (const PT& o) const { return {x + o.x, y + o.y}; }
    PT operator* (ll k) const { return {k*x, k*y}; }

    // products
    ll operator* (const PT& o) const { return x*o.x + y*o.y; }
    ll operator% (const PT& o) const { return x*o.y - y*o.x; }

    // sorting
    bool operator< (const PT& o) const { return x == o.x ? y < o.y : x < o.x; }
    bool operator== (const PT& o) const { return x == o.x && y == o.y; }

    // input/output
    friend ostream& operator<< (ostream& os, PT& o) {
        return os << o.x << ' ' << o.y;
    }
    friend istream& operator>> (istream& is, PT& o) {
        return is >> o.x >> o.y;
    }
};

struct Polygon {
    int sides;
    vector<PT> p;
    Polygon (vector<PT>&& v) : sides(v.size()), p(v) {}
    int next (int i) {
        return i == sides - 1 ? 0 : i + 1;
    }
    ll shoelace();
};

ll Polygon::shoelace () {
    ll sum = 0;
    for (int i = 0; i < sides; i++){
        sum += p[i] % p[next(i)];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n && n!= 0){
        PT point;
        vector<PT> polygonPoints;
        for(int i=0; i<n; i++){
            cin>>point;
            polygonPoints.push_back(point);
        }
        Polygon polygon(static_cast<vector<struct PT> &&>(polygonPoints));
        ld resp = ((ld)polygon.shoelace())/2;
        cout << fixed<< setprecision(1);;
        if(resp>0) cout<<"CCW "<<resp<<endl;
        else cout<<"CW "<<abs(resp)<<endl;
    }
    return 0;
}
