#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(value) value.begin(), value.end()
#define fo(x, temp_set_for_mex, fi) for(ll x = temp_set_for_mex; x < fi; x++)
#define forr(x, temp_set_for_mex, fi) for(ll x = temp_set_for_mex; x <= fi; x++)
#define rrof(x, temp_set_for_mex, fi) for(ll x = temp_set_for_mex; x >= fi; x--)
#define roff(x, temp_set_for_mex, fi) for(ll x = temp_set_for_mex; x >= fi; x--)
#define of(x, temp_set_for_mex, fi) for(ll x = temp_set_for_mex; x > fi; x--)
#define ro(x, temp_set_for_mex, fi) for(ll x = temp_set_for_mex; x > fi; x--)
#define yes(x) (x ? "YES" : "NO")
#define endl '\n'
#ifdef LOCAL
#include <algo/debug.h>
#else
#define debug(...) 68
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distrib(1ll, 200000ll);
constexpr ll N = (ll)(1e15);
constexpr ll MOD99 = 998244353;
constexpr ll MOD7 = 1e9 + 7;
/*
void copy_this () {
    ll n; cin >> n;
    ll n, k; cin >> n >> k;
    ll n, q; cin >> n >> q;
    ll a[n]; fo(i, 0, n) cin >> a[i];
    vector<ll> a(n); fo(i, 0, n) cin >> a[i];
}
*/
struct segment {
    ld x1, y1, x2, y2;
};
bool touches_point(segment s, ld Ox, ld Oy, ld Or) {
    ld Or_squared=Or*Or;
    ld tocenter1 = (s.x1-Ox)*(s.x1-Ox)+(s.y1-Oy)*(s.y1-Oy);
    if (tocenter1 < Or_squared) {
        return true;
    }
    return false;
}
bool touches(segment s, ld Ox, ld Oy, ld Or) {
    ld Or_squared=Or*Or;
    s.x1 -= Ox;
    s.y1 -= Oy;
    s.x2 -= Ox;
    s.y2 -= Oy;
    ld dx = s.x2 - s.x1;
    ld dy = s.y2 - s.y1;
    ld a = dx*dx + dy*dy;
    ld b = 2.*(s.x1*dx + s.y1*dy);
    ld c = s.x1*s.x1 + s.y1*s.y1 - Or_squared;
    if (-b < 0) return (c < 0);
    if (-b < (2.*a)) return ((4.*a*c - b*b) < 0);
    return (a+b+c < 0);
}
ll n;
vector<segment> a;
ld g(ld x, ld y) {
    ld rad_l=0, rad_r=1e4;
    while (rad_r-rad_l > 1e-9) {
        ld rad_mid = (rad_l+rad_r)/2;
        bool touches_everything = true;
        fo(i, 0, n) {
            if (!touches(a[i], x, y, rad_mid)) {
                touches_everything = false;
                break;
            }
        }
        if (touches_everything) {
            rad_r = rad_mid;
        } else {
            rad_l = rad_mid;
        }
    }
    return rad_l;
}
ld f(ld x) {
    ld res = 1e9;
    ld l = -1e4;
    ld r = 1e4;
    while (r-l > 1e-9) {
        ld y1 = l + (r - l) / 3;
        ld y2 = r - (r - l) / 3;
        ld gy1 = g(x, y1);
        ld gy2 = g(x, y2);
        if (gy1 > gy2) {
            l = y1;
        } else {
            r = y2;
            res = gy2;
        }
    }
    return res;
}
void solve() {
    cout << setprecision(10);
    clog << setprecision(10);
    cin >> n;
    a.resize(n);
    fo(i, 0, n) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    ld l = -2e4;
    ld r = 2e4;
    ld res = 1e9;
    while (r-l > 1e-9) {
        ld x1 = l + (r - l) / 3;
        ld x2 = r - (r - l) / 3;
        ld fx1 = f(x1);
        ld fx2 = f(x2);
        if (fx1 > fx2) {
            l = x1;
        } else {
            r = x2;
            res = fx2;
        }
    }
    cout << res << endl;
}
int32_t main (int32_t argc, char* argv[]) {
    // Задача про мин покрывающий диск
    // f(x), g(y) - непр убывает а после непр возрастает
    // f(x) - мин покрывающий диск на этом иксе
    // g(y) - мин покрывающий диск на этом игреке
    bool use_fast_io = true;
    for (int32_t i = 1; i < argc; ++i)
        if (string(argv[i]) == "-local-no-fast-io") {
            use_fast_io = false;
//            cout << "No fastIO" << endl;
            break;
        }
    if (use_fast_io) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cerr.tie(nullptr);
        //clog.tie(nullptr);
    }
    ll tt = 1;
//    cin >> tt;
    while (tt--) solve();
    return 0;
}