#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace __gnu_pbds;
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


class OrderedSet {
private:
    typedef tree<long long,
            null_type,
            less_equal<long long>,
            rb_tree_tag,
            tree_order_statistics_node_update> ordered_set;
    ordered_set s;

public:
    void Insert(long long x) {
        s.insert(x);
    }

    bool Exist(long long x) {
        if (s.upper_bound(x) == s.end()) {
            return false;
        }
        return (*s.upper_bound(x)) == x;
    }

    void Erase(long long x) {
        if (Exist(x)) {
            s.erase(s.upper_bound(x));
        }
    }

    int Idx(long long x) {
        if (!Exist(x)) {
            return -1;
        }
        return s.order_of_key(x);
    }

    int LastIdx(long long x) {
        if (!Exist(x)) {
            return -1;
        }
        if (*s.find_by_order(s.size() - 1) == x) {
            return s.size() - 1;
        }
        return Idx(*s.lower_bound(x)) - 1;
    }

    long long Value(int index) {
        return *s.find_by_order(index);
    }

    int Count(long long x) {
        if (!Exist(x)) {
            return 0;
        }
        return LastIdx(x) - Idx(x) + 1;
    }

    void Clear() {
        s.clear();
    }

    int Size() {
        return s.size();
    }

    int Lower_bound(int x) {

        return *s.upper_bound(x);
    }

    int Upper_bound(int x) {

        return *s.lower_bound(x);
    }

};

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

void solve(){
    ll n,q;cin>>n>>q;
    vi a(n);cin(a);
    map<ll,ll>mp;
    ordered_set st;
    for(int i=0;i<n;i++)
    {
        if(mp.find(a[i])==mp.end())
            mp[a[i]]=i;
        st.insert(i);
    }
    ll fi=-1;
    while(q--)
    {
        ll ch;cin>>ch;
        ll ans=st.order_of_key(mp[ch]);
        cout<<ans+1<<ln;
        st.erase(st.find(mp[ch]));
        st.insert(fi);
        mp[ch]=fi;
        fi--;
    }


}

int main() {
    speed;
    input();
    preprocessing();
    ll t;
    cin >> t;
//    t = 1;
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