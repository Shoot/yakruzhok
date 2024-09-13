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
uniform_int_distribution<ll> distrib(100, 900);
constexpr ll N = (ll)(2e4);
constexpr ll MOD = 998244353;
ll powm(ll a, ll b){
    ll d = 1;
    while(b){
        if (b&1) d = (d*a) % MOD;
        b >>= 1;
        a = (a*a) % MOD;
    }
    return d;
}
/*
void copy_this () {
    ll n; cin >> n;
    ll n, k; cin >> n >> k;
    ll n, q; cin >> n >> q;
    ll a[n]; fo(i, 0, n) cin >> a[i];
    vector<ll> a(n); fo(i, 0, n) cin >> a[i];
}
*/
ll mul(ll a, ll b) {
    return (a*b)%MOD;
}
ll div2(ll a) {
    return mul(a, powm(2, MOD-2));
}
void solve () {
    ll a, b; cin >> a >> b;
    if (b == 0) {
        cout << 0 << endl;
        return;
    }
//    b%=MOD; // !!!!!! ????????
    map<ll, ll> divs;
    for (int i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            ++divs[i];
            a /= i;
        }
    }
    if (a > 1) divs[a]++; // мб простое
    ll d = b;
    clog << "d = " << d << endl;
    for (auto [div, pwr] : divs) {
        cout << "div=" << div << endl;
        d*=b*pwr+1;
        clog << b*pwr+1 << endl;
    }
    d/=2;
    d%=MOD;
    // d = (b*e_1+1)*(b*e_2+1)*...*(b*e_n+1)/2, тк было p_i^e_i а стало p_i^(e_i*b)
    // C=(a^b)^(d/2)=a^(b*d/2)
    // Ответ: (b*d/2)  ^^^^^^^
    cout << (ll)d << endl;
}
int32_t main (int32_t argc, char* argv[]) {
    // произведение всех делителей = ...
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
        clog.tie(nullptr);
    }
    ll tt = 1;
//    fo(i, 0, 1) skip.insert(distrib(rng));
//    cin >> tt;
    while (tt--) solve();
    return 0;
}