#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define yes cout << "YES"<<'\n';
#define no cout << "NO"<<'\n';
#define nl "\n"
#define sz(s) (int) (s).size()
#define fr(n) for (int i = 0; i < n; ++i)
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
#define ld long double
#define aw3dni_ink_tet3aleg ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
const double PI = 3.14159265359;
#define sp(x) fixed << setprecision(x)
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define put(x) return void(cout << x)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define cin(vec)                                                                                                       \
    for (auto &i: vec)                                                                                                 \
    cin >> i
#define cout(vec)                                                                                                      \
    for (auto &i: vec)                                                                                                 \
        cout << i << " ";                                                                                              \
    cout << "\n";
#define ON(n, k) ((n) | (1ll << (k)))
#define OFF(n, k) ((n) & ~(1ll << (k)))
#define isON(n, k) (((n) >> (k)) & 1)
#define flip(n, k) ((n) ^ (1ll << (k)))
#define popcnt(x) (__builtin_popcountll(x))
const ll oo = 0x3f3f3f3f3f3f3f3f, MOD = 32768;

template<typename T = int>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v)in >> x;
    return in;
}

template<typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const T &x: v)out << x << ' ';
    return out;
}

void FILES() {
    aw3dni_ink_tet3aleg
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

#define ceil_i(a, b) (((ll) (a) + (ll) (b - 1)) / (ll) (b))
#define floor_i(a, b) (a / b)
#define round_i(a, b) ((a + (b / 2)) / b)

#define INF LLONG_MAX

int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};
// up right down left

const ll N = 3e5 + 5;

bool com(pair<char,ll> a, pair<char,ll> b) {
    return a.ss < b.ss;
}

int go(int a, int b, int c) {
    return (b / c) + ((a - 1) / c);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(all(v));
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        ll sum =v[i]+v[n-i-1];
        ans =min(ans,sum);
    }
    cout<<ans;
}

// وَقُلْ رَبِّ زِدْنِي عِلْمًا
signed main() {
    //=========================================================================
    FILES();
    //=========================================================================
    int T = 1, t = 1;
    // cin >> T;
    //    PascalPyramid();
    while (T--) {
        solve();
        t++;
        cout << nl;
    }
    return 0;
}
