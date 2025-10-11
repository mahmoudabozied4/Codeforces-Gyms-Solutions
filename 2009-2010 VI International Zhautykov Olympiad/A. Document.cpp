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
const int N = 4e6 + 5, M = 1'000'000'007, OO = 0X3F3F3F3F3F3F3F3F;
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

template<class T>
struct Sparetable {
    vector<vector<T> > v;
    int n, LOG;

    void init(vector<T> &a) {
        this->n = (int) a.size();
        this->LOG = 0;
        int size = 1;
        while (size <= n) size *= 2, LOG++;
        v.assign(n, vector<T>(LOG));
        for (int i = 0; i < n; i++)v[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                v[i][j] = merge(v[i][j - 1], v[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T merge(T a, T b) {
        return a | b; // change the operation
    }

    T qry(int l, int r) {
        int len = r - l + 1;
        int j = 31 - __builtin_clz(len);
        T res = merge(v[l][j], v[r - (1 << j) + 1][j]);
        return res; // determine what you want to return
    }
};

auto Solve(const int &n) -> int {
    int cur = 0, ans = 0;
	vi v(5);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> v[j];
		}
		while (v[cur] == 0) {
			ans++;
			cur++;
			if (cur == 5)
				cur = 0, ans += 2;
		}

		cur++;
		ans++;
		if (cur == 5 && i < n - 1)
			cur = 0, ans += 2;
	}
    return ans;
}


bool solve_test(const int test_number) {
    int n;
    if (!(cin >> n))
        return false;
    // Solve(n);
    auto ans = Solve(n);
    cout << ans << endl;
    return true;
}

void Stress() {
    // for (int n = 2; n <= 1; ++n)
    //     cerr << n << ' ' << Solve(n) << '\n';
}

int32_t main() {
    Zied();
    Stress();
    freopen("document.in", "r", stdin);
    freopen("document.out", "w", stdout);
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
