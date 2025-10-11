#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int long long
#define ull unsigned long long
#define endl '\n'
typedef pair<int, int> pii;
#define elif else if
#define endd(s) return void(cout << s << "\n")
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define X first
#define Y second
#define fixed(n) fixed << setprecision(n)
#define sz(s) int32_t(s.size())
#define dbg(x) cout << #x << ": " << (x) << "\n";
#define getline(s) getline(cin >> ws, s)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define all(vec) vec.begin(), vec.end()
#define rall(v) v.rbegin(),v.rend()
#define mul_mod(a, b) (((a % M) * (b % M)) % M)
#define add_mod(a, b) (((a % M) + (b % M)) % M)
#define sub_mod(a, b) (((a % M) - (b % M) + M) % M)
const int N = 1e5 + 5, M = 1'000'000'007, OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9, pi = 3.141592653589793;
#define kill return 0
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
vector<string> RET = {"NO", "YES"};
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void Zied() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

template<typename T = int>
istream &operator >>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}

template<typename T = int>
ostream &operator <<(ostream &out, const vector<T> &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

template<typename A, typename B>
istream &operator>>(istream &fin, pair<A, B> &p) {
    fin >> p.X >> p.Y;
    return fin;
}

template<typename A, typename B>
std::ostream &operator<<(std::ostream &fout, const std::pair<A, B> &p) {
    fout << p.first << " " << p.second;
    return fout;
}

enum dir { d, r, u, l, ul, dr, ur, dl };

int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
vi a7a;

void preprocessing() {
}

struct coordinateCopmression {
private:
    vector<ll> init;

    void compress(vector<ll> &v) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

public:
    coordinateCopmression(vector<ll> &v) {
        init = v;
        compress(init);
    }

    int index(ll val) {
        return lower_bound(init.begin(), init.end(), val) - init.begin();
    }

    ll initVal(int idx) {
        return init[idx];
    }
};

int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int modInverse(int a, int mod) {
    return power(a, mod - 2, mod);
}

auto Solve(const int &n) -> void {
    vi a(n);
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    vector<pair<vi, pair<int, int>>> v;

    for (int mask = 1; mask < (1 << n); mask++) {
        int product = 1;
        vi subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.pb(a[i]);
                product = mul_mod(product, a[i]);
            }
        }
        v.emplace_back(subset, make_pair(mask, product));
    }

    sort(all(v), [](const auto &x, const auto &y) {
        return x.X < y.X;
    });

    vi b,masks;
    for (auto it: v) {
        b.pb(it.Y.Y);
        masks.pb(it.Y.X);
    }

    int q;
    cin >> q;
    vvi xors(n, vi(sz(b) + 1, 0));

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        int j = mp[x];
        xors[j][l] ^= 1;
        xors[j][r + 1] ^= 1;
    }

    vvi xorx(n, vi(sz(b), 0));
    for (int j = 0; j < n; j++) {
        int cur = 0;
        for (int i = 0; i < sz(b); i++) {
            cur ^= xors[j][i];
            xorx[j][i] = cur;
        }
    }
vi inv(n);
    for (int i = 0; i < n; ++i) {
        inv[i] = modInverse(a[i] , M);
    }
    for (int i = 0; i < sz(b); i++) {
        int cur = v[i].Y.X;
        for (int j = 0; j < n; j++) {
            if (xorx[j][i] & 1) {
                if (cur & (1 << j)) b[i] = mul_mod(b[i] , inv[j]);
                else b[i] = mul_mod(b[i] , a[j]);
            }
        }
    }

    cout << b << endl;
}


bool solve_test(const int test_number) {
    int n;
    if (!(cin >> n))
        return false;
    Solve(n);
    // auto ans = Solve(n);
    // cout << ans << endl;
    return true;
}

void Stress() {
    // for (int n = 2; n <= 1; ++n)
    //     cerr << n << ' ' << Solve(n) << '\n';
}

int32_t main() {
    Zied();
    Stress();
    // freopen("document.in", "r", stdin);
    // freopen("document.out", "w", stdout);
    preprocessing();
    int test_cases = 1;
    // cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        // cout << "Case " << tc << ": " << endl;
        if (!solve_test(tc))break;
        //                cout << endl;
    }
    kill;
    //    Time
}

/*
              ,   .-'"'=;_  ,
              |\.'-~`-.`-`;/|
              \.` '.'~-.` './
              (\`,__=-'__,'/)
           _.-'-.( d\_/b ).-'-._
         /'.-'   ' .---. '   '-.`\
       /'  .' (=    (_)    =) '.  `\
      /'  .',  `-.__.-.__.-'  ,'.  `\
     (     .'.   V       V  ; '.     )
     (    |::  `-,__.-.__,-'  ::|    )
     |   /|`:.               .:'|\   |
     |  / | `:.              :' |`\  |
     | |  (  :.             .:  )  | |
     | |   ( `:.            :' )   | |
     | |    \ :.           .: /    | |
     | |     \`:.         .:'/     | |
     ) (      `\`:.     .:'/'      ) (
     (  `)_     ) `:._.:' (     _(`  )
     \  ' _)  .'           `.  (_ `  /
      \  '_) /   .'"```"'.   \ (_`  /
       `'"`  \  (         )  /  `"'`
   ___   MZ   `.`.       .'.'        ___
 .`   ``"""'''--`_)     (_'--'''"""``   `.
(_(_(___...--'"'`         `'"'--...___)_)_)
*/
