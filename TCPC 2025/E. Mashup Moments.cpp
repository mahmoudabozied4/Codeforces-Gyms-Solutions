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

int idx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int idy[] = {0, 0, -1, 1, -1, 1, 1, -1};
char dir[] = {'D', 'L', 'U', 'R'};
const ll N = 1e9 + 5;
void preprocessing() {

}

void solve() {
    ll n , q, m;cin>>n>>q>>m;
    vi v(n);cin(v);
    vector<string> s(n);cin(s);
    while(q--)
    {
        ll x;cin>>x;
        auto it= upper_bound(all(v),x)-v.begin();
        cout<<s[it-1]<<ln;
    }
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
