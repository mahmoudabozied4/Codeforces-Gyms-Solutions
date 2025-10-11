#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define ln '\n'
#define yes "YES"
#define no  "NO"
#define spa " "
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define cin(v) for(auto &ii:v)cin>>ii
#define cout(v) for(auto &iit:v)cout<<iit<<spa
#define sp(x) fixed<<setprecision(x)
#define put(n) return void(cout<<n<<ln)
#define ff first
#define ss second
#define oo 1e18
#define pb(x) push_back(x)
#define mpp(v) for(auto i:v)mp[i]++
#define speed ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define forr(i,k, n) for (int i = k; i < (n); i++)
#define rforr(i, n) for (int i = (n) - 1; i >= 0; i--)
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vbo;
ll mod = 1e9 + 7;
random_device rd;
mt19937 mt(rd());

int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(mt);
}

ll add(ll a, ll b) {
    return (a % mod + b % mod) % mod;
}

ll subtract(ll a, ll b) {
    return (a % mod - b % mod + 2 * mod) % mod;
}

ll mul(ll a, ll b) {
    return (a % mod * b % mod) % mod;
}

ll gcd(ll a, ll b) {
    if (b == 0)return a;
    return gcd(a, a % b);
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll mod_div(ll a, ll b) {
    return a * power(b, mod - 2) % mod;
}

ll fastPower(ll a, ll b, ll m) {
    if (b == 0)
        return 1;
    ll res = fastPower(a, b / 2, m);
    res = (res * res) % m;
    if (b % 2)
        res = (res * a) % m;
    return res;
}

void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // freopen("metro.in", "r", stdin);
    // freopen("mex.in", "w", stdout);
#endif
}

const ll N = 1e9 + 5;

void preprocessing() {
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    cin(v);
    string s;
    cin >> s;
    map<char, ll> mp;
    for (auto i: s)mp[i]++;
    vector<vvi> pre(n + 1, vvi(m + 1, vi(26, 0)));
    forr(i, 1, n+1) {
        forr(j, 1, m+1) {
            forr(c, 0, 26) {
                pre[i][j][c] = pre[i - 1][j][c] + pre[i][j - 1][c] - pre[i - 1][j - 1][c];
            }
            ll ch = v[i - 1][j - 1] - 'a';
            pre[i][j][ch]++;
        }
    }
    auto can = [&](ll mid) {
        for (int i = 0; i <= n - mid; i++) {
            for (int j = 0; j <= m - mid; j++) {
                bool flag = 1;
                for (auto it: mp) {
                    ll ch = (it.ff - 'a');
                    ll l = i + mid;
                    ll r = j + mid;
                    ll sum = pre[l][r][ch] - pre[l][j][ch] - pre[i][r][ch] + pre[i][j][ch];
                    if (sum < it.ss) {
                        flag = 0;
                        break;
                    }
                }
                if (flag)return 1;
            }
        }
        return 0;
    };

    ll st = 1, en = min(n, m), ans = -1;
    while (st <= en) {
        ll mid = (st + en) / 2;
        if (can(mid)) {
            ans = mid;
            en = mid - 1;
        } else
            st = mid + 1;
    }
    if (ans == -1)
        cout << -1 << ln;
    else
        cout << ans * ans << ln;
}

int main() {
    speed;
    input();
    preprocessing();
    ll t;
    //    cin >> t;
    t = 1;
    while (t--) {
        solve();
        /*
        ⢸⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⡷⠀⠀
        ⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠢⣀⠀⠀
        ⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇ Did you get accepted, son?
        ⢸⠀⠀⠀⠀ ⠖⠒⠒⠒⢤⠀⠀⠀⠀⠀⡇⠀⠀
        ⢸⠀⠀⣀⢤⣼⣀⡠⠤⠤⠼⠤⡄⠀⠀⡇⠀
        ⢸⠀⠀⠑⡤⠤⡒⠒⠒⡊⠙⡏⠀⢀⠀⡇⠀
        ⢸⠀⠀⠀⠇⠀⣀⣀⣀⣀⢀⠧⠟⠁⠀⡇
        ⢸⠀⠀⠀⠸⣀⠀⠀⠈⢉⠟⠓⠀⠀⠀⠀
        ⢸⠀⠀⠀⠀⠈⢱⡖⠋⠁⠀⠀⠀⠀⠀⠀⡇
        ⢸⠀⠀⠀⠀⣠⢺⠧⢄⣀⠀⠀⣀⣀⠀⠀⡇
        ⢸⠀⠀⠀⣠⠃⢸⠀⠀⠈⠉⡽⠿⠯⡆
        ⢸⠀⠀⣰⠁⠀⢸⠀⠀⠀⠀⠉⠉⠉⠀⠀⡇
        ⢸⠀⠀⠣⠀⠀⢸⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀
        ⢸⠀⠀⠀⠀⠀⢸⠀⢇⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀
        */
    }
    return 0;
}
