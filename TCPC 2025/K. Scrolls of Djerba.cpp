#include <bits/stdc++.h>

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

ll OO = 1e17, MOD = 1e9 + 7; //1e9 + 7 ,,998244353

// int add(int a, int b) { return ((a % MOD) + (b % MOD) + MOD) % MOD; }
//
// int mul(int a, int b) { return (((a % MOD) * (b % MOD))) % MOD; }
int add(int a, int b) {
    return (0ll + a + b + MOD) % MOD;
}

int mul(int a, int b) {
    return (1ll * a * b) % MOD;
}

int sub(int a, int b) { return (((a % MOD) - (b % MOD)) + MOD) % MOD; }


#define INF 1e18

int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};
// up right down left

const int N = 1e6 + 5, X = 105, EPS = 1e-12;

// وَقُلْ رَبِّ زِدْنِي عِلْمًا

ll fact[N + 1], inv_fact[N + 1];

ll modPow(ll x, ll n, ll mod) {
    x %= mod;
    ll res = 1;
    while (n > 0) {
        if (n % 2) res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

void factorial() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
}

void inv_factorial() {
    inv_fact[N] = modPow(fact[N], MOD - 2, MOD);
    for (int i = N; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
}

ll NCR(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

void pre_count() {
    factorial();
    inv_factorial();
}
bool is_subseq(const string &s, const string &t) {
    int j = 0;
    for (char c : t) {
        if (j < s.size() && c == s[j]) j++;
    }
    return j == s.size();
}
void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(all(v), [](const string &s1, const string &s2) {
        return s1.size() < s2.size();
    });
    unordered_set<string> subseq;
    string &first = v[0];
    int m = first.size();
    for (int mask = 1; mask < (1 << m); ++mask) {
        string sub;
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i))
                sub += first[i];
        }
        subseq.insert(sub);
    }
    string res = "";
    for ( auto &it : subseq) {
        bool valid = true;
        for (int i = 1; i < n; ++i) {
            if (!is_subseq(it, v[i])) {
                valid = false;
                break;
            }
        }
        if (valid) {
            if (it.size() > res.size() || (it.size() == res.size() && it < res)) {
                res = it;
            }
        }
    }
    if (res.empty()) return void(cout << -1);
     cout << res ;
}

signed main() {
    //=========================================================================
    FILES();
    //=========================================================================
    int T = 1, t = 1;
    // phi_1_to_n();
    // linear_sieve(1e6);
    // pre_count();
    // sieve();
    // PascalPyramid();
    // computeCatalan();
    // preprocess(50);
    // totient_sieve();
    // cin >> T;
    while (T--) {
        solve();
        t++;
        // vid++;
        cout << nl;
    }
    return 0;
}
