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

ll OO = 0x3f3f3f3f3f3f3f3f, MOD = 1e9 + 7; //1e9 + 7 ,,998244353

int add(int a, int b) { return ((a % MOD) + (b % MOD) + MOD) % MOD; }

int mul(int a, int b) { return (((a % MOD) * (b % MOD))) % MOD; }

int sub(int a, int b) { return (((a % MOD) - (b % MOD)) + MOD) % MOD; }


#define INF 1e18

int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};
// up right down left
const int N = 1e6 + 1, X = 101, EPS = 1e-12;
ll inv[N + 1], cat[N + 1];
ll fib[50];
map<ll,ll> mp;

void preProcess() {
    // inv[0] = 1;
    // inv[1] = 1;
    // for (int i = 2; i <= N; i++) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    // cat[0] = 1;
    // for (ll i = 0; i < N - 3; i++) {
    //     cat[i + 1] = (4ll * i + 2ll) * cat[i] % MOD;
    //     cat[i + 1] = cat[i + 1] * inv[i + 2] % MOD;
    // }
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 50; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// void preProcess() {
//     cat[0] = 1;
//     // Compute Catalan numbers: C_{n+1} = (4n + 2)/(n + 2) * C_n
//     for (int i = 0; i < 10; i++) {
//         cat[i + 1] = (4LL * i + 2) * cat[i] / (i + 2);
//     }
// }
// ll catalan (int n) {
//     f ==>> array
//     return f[2*n]/f[n]/f[n+1];
// }

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

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    ll res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= (n - r + i);
        res /= i;
    }
    return res;
}


// ll stars_and_bars(int elements, int places) {
//     return NCR(elements + places - 1, elements);
// }

ll fix(ll x) { return (x % MOD + MOD) % MOD; }
ll derangement(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 1;
    ll d0 = 1, d1 = 0, d2 = 1;
    for (int i = 3; i <= n; ++i) {
        ll d = (i - 1) * (d1 + d2);
        d1 = d2;
        d2 = d;
    }
    return d2;
}

ll fp(ll basic, ll power) {
    ll ans = 1;
    while (power) {
        if (power % 2) { ans = (ans * basic); }
        basic = (basic * basic);
        power /= 2;
    }
    return ans;
}

bool prime[N + 1];
vector<ll> primes;

void sieve() {
    memset(prime, true, sizeof(prime));
    prime[2] = true;
    for (int p = 2; p <= N; p++) {
        if (prime[p]) {
            primes.push_back(p);
            for (int i = p * 2; i <= N; i += p) {
                prime[i] = false;
            }
        }
    }
}

map<ll, int> factorization;

void factorize(ll x) {
    for (auto p: primes) {
        if (p * p > x)
            break;

        while (x % p == 0) {
            factorization[p]++;
            x /= p;
        }
    }
    if (x != 1)
        factorization[x]++;
}

int extended_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    // call all and save answer back
    int gcdd = extended_euclid(b, a % b, x1, y1);
    x = y1;
    int q = a / b;
    y = x1 - q * y1;
    return gcdd;
    /*
     * if u  have x,y is a sol if u  want all possible solutions
     * new_x = x + ((K*b)/g)
     * new_y = y - ((K*a)/g)
     * k==> is a integer
     */
}

void solve() {
    int n;
    ll s;
    cin >> n >> s;
    vector<ll> a(n);
    cin >> a;
    map<ll, ll> freq;
    freq[0] = 1;
    ll sum = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        count += freq[sum - s];
        freq[sum]++;
    }
    cout << count;
}


signed main() {
    //=========================================================================
    FILES();
    //=========================================================================
    int T = 1, t = 1;
    // pre_count();
    // sieve();
    // PascalPyramid();
    // preProcess();
    // cin >> T;
    while (T--) {
        solve();
        t++;
        // cout << nl;
    }
    return 0;
}
