#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define pii pair<ll,ll>
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

const ll OO = 0x3f3f3f3f3f3f3f3f, MOD = 1e9 + 7; //1e9 + 7 ,,998244353

int add(int a, int b,int mo) { return ((a % mo) + (b % mo) + mo) % mo; }

int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }

int sub(int a, int b) { return (((a % MOD) - (b % MOD)) + MOD) % MOD; }


#define INF INT_MAX

int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};
// up right down left
void preProcess() {
}

const int N = 1e3 + 1, X = 100, EPS = 1e-9;

void solve() {
    ld a , b, c,d ;
    cin >> a>> b >> c >> d;
    ld dis1 = sqrt(((a - 0) * (a - 0)) + ((b - 0) * (b - 0)));
    ld dis2 = sqrt(((c - 0) * (c - 0)) + ((d - 0) * (d - 0)));
    if (abs(dis1-dis2) <= EPS) {
        cout <<"Empate";
    }
    else if (dis1 < dis2) {
        cout <<"Russo";
    }
    else {
        cout <<"Wil";
    }
}


// وَقُلْ رَبِّ زِدْنِي عِلْمًا
signed main() {
    //=========================================================================
    FILES();
    //=========================================================================
    int T = 1, t = 1;
    // pre_count();
    // sieve();
    // PascalPyramid();
    // cin >> T;
    while (T--) {
        // preProcess();
        solve();
        t++;
        cout << nl;
    }
    return 0;
}
