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
const int N = 1 << 17, M = 1'000'000'007, OO = 0X3F3F3F3F3F3F3F3F;
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

void preprocessing(int n = 1e7) {
}

struct SegmentTree {
    struct Node {
        int s1, s2, s3, lz;

        Node(): s1(0), s2(0), s3(0), lz(0) {
        }
    };

    int n;
    vector<Node> seg;

    SegmentTree(const vector<int> &A): n(A.size()) {
        seg.resize(4 * n);
        build(1, 0, n - 1, A);
    }

    // Apply “add x” to node idx covering length m
    void apply(int idx, int m, int x) {
        x %= M;
        int x2 = mul_mod(x, x), x3 = mul_mod(x2, x);
        // sum(a[i]^3) + 3 * x * sum(a[i]^2) + 3 * x^2 * sum(a[i]) + x^3 * (r - l)
        seg[idx].s3 = add_mod(seg[idx].s3,
                              add_mod(add_mod(mul_mod(3*x % M, seg[idx].s2), mul_mod(3*x2 % M, seg[idx].s1)), mul_mod(m,
                                  x3)));
        // sum(a[i]^2) + 2 * x * sum(a[i]) + x^2 * (r - l)
        seg[idx].s2 = add_mod(seg[idx].s2, add_mod(mul_mod(2*x % M, seg[idx].s1), mul_mod(m, x2)));
        // sum(a[i]) + x * (r - l)
        seg[idx].s1 = add_mod(seg[idx].s1, mul_mod(m, x));
        // propaget
        seg[idx].lz = add_mod(seg[idx].lz, x);
    }

    void push(int idx, int l, int r) {
        if (seg[idx].lz && l < r) {
            int mid = (l + r) >> 1;
            apply(idx << 1, mid - l + 1, seg[idx].lz);
            apply(idx << 1 | 1, r - (mid + 1) + 1, seg[idx].lz);
            seg[idx].lz = 0;
        }
    }

    void pull(int idx) {
        seg[idx].s1 = add_mod(seg[idx<<1].s1, seg[idx<<1|1].s1);
        seg[idx].s2 = add_mod(seg[idx<<1].s2, seg[idx<<1|1].s2);
        seg[idx].s3 = add_mod(seg[idx<<1].s3, seg[idx<<1|1].s3);
    }

    void build(int idx, int l, int r, const vector<int> &A) {
        if (l == r) {
            int v = A[l] % M;
            seg[idx].s1 = v;
            seg[idx].s2 = mul_mod(v, v);
            seg[idx].s3 = mul_mod(seg[idx].s2, v);
        } else {
            int mid = (l + r) >> 1;
            build(idx << 1, l, mid, A);
            build(idx << 1 | 1, mid + 1, r, A);
            pull(idx);
        }
    }

    void update(int idx, int l, int r, int ql, int qr, int x) {
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            apply(idx, r - l + 1, x);
            return;
        }
        push(idx, l, r);
        int mid = (l + r) >> 1;
        update(idx << 1, l, mid, ql, qr, x);
        update(idx << 1 | 1, mid + 1, r, ql, qr, x);
        pull(idx);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return Node();
        if (ql <= l && r <= qr)
            return seg[idx];
        push(idx, l, r);
        int mid = (l + r) >> 1;
        Node L = query(idx << 1, l, mid, ql, qr);
        Node R = query(idx << 1 | 1, mid + 1, r, ql, qr);
        Node res;
        res.s1 = add_mod(L.s1, R.s1);
        res.s2 = add_mod(L.s2, R.s2);
        res.s3 = add_mod(L.s3, R.s3);
        return res;
    }

    void update(int ql, int qr, int x) {
        update(1, 0, n - 1, ql, qr, x);
    }

    int query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr).s3;
    }
};


auto Solve(const int &n) {
    vi a(n);
    cin >> a;

    SegmentTree lzy(a);
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            lzy.update(l - 1, r - 1, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << lzy.query(l - 1, r - 1) << endl;
        }
    }
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
