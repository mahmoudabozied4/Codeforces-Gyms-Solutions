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
const int N = 4e5 + 20 , M = 1'000'000'007, OO = 0X3F3F3F3F3F3F3F3F;
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

void preprocessing() {
}

struct node {
    long long sum, lzAdd, lzSet;

    void set(long long v, int ns, int ne) {
        sum = v * (ne - ns + 1);
        lzSet = v;
        lzAdd = 0;
    }

    void add(long long v, int ns, int ne) {
        sum += v * (ne - ns + 1);
        lzAdd += v;
    }
}

nodes [N];

void pushDown(int ni, int ns, int ne) {
    if (ns == ne)return;
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    if (nodes[ni].lzSet != -1) {
        nodes[l].set(nodes[ni].lzSet, ns, m);
        nodes[r].set(nodes[ni].lzSet, m + 1, ne);
        nodes[ni].lzSet = -1;
    }
    if (nodes[ni].lzAdd) {
        nodes[l].add(nodes[ni].lzAdd, ns, m);
        nodes[r].add(nodes[ni].lzAdd, m + 1, ne);
        nodes[ni].lzAdd = 0;
    }
}

int arr[N], n;

node merge(const node &a, const node &b) {
    return {a.sum + b.sum, 0, -1};
}

void build(int ni = 0, int ns = 0, int ne = n - 1) {
    if (ns == ne) {
        nodes[ni] = {arr[ns], 0, -1};
        return;
    }
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    build(l, ns, m);
    build(r, m + 1, ne);
    nodes[ni] = merge(nodes[l], nodes[r]);
}

void update(int qs,int qe,int v, bool isAdd = 1, int ni = 0, int ns = 0, int ne = n - 1) {
    if (qs > ne || qe < ns)return;
    if (qs <= ns && qe >= ne) {
        if (isAdd) {
            nodes[ni].add(v, ns, ne);
        } else {
            nodes[ni].set(v, ns, ne);
        }
        return;
    }
    pushDown(ni, ns, ne);
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    update(qs, qe, v, isAdd, l, ns, m);
    update(qs, qe, v, isAdd, r, m + 1, ne);
    nodes[ni] = merge(nodes[l], nodes[r]);
}

node query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
    if (qs > ne || qe < ns)return {0, 0, -1};
    if (qs <= ns && qe >= ne)return nodes[ni];
    pushDown(ni, ns, ne);
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    return merge(query(qs, qe, l, ns, m), query(qs, qe, r, m + 1, ne));
}

auto Solve(const int &n) {
    int q;cin >> q;
    for (int i = 0; i < n; ++i) arr[i] = 0;
    build();

    vector<string> ret{"yes sir" , "negative"} ,ans;
    for (int i = 0; i < q; ++i) {
        char ty; int  s, e;
        cin >> ty >> s >> e;
        if (ty == '!') {
            int x ; cin >> x;
            update(s-1, e-1, x);
        }else {
            int need = query(s-1, s-1).sum;
            if (need >= e) {
                ans.pb(ret[0]);
                update(s-1, s-1, -e);
            } else {
                ans.pb(ret[1]);
            }
        }
    }
    return ans ;
}

bool solve_test(const int test_number) {
    if (!(cin >> n))
        return false;
    // Solve(n);
    auto ans = Solve(n);
    for (auto &it: ans) cout << it << '\n';
    return true;
}

void Stress() {
    // for (int n = 2; n <= 1; ++n)
    //     cerr << n << ' ' << Solve(n) << '\n';
}

int32_t main() {
    Zied();
    Stress();
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
