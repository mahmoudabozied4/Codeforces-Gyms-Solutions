#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int long long
typedef unsigned long long ull;
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
const int N = 2e5 + 10, M = 1'000'000'007, OO = 0X3F3F3F3F3F3F3F3F;
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


auto Solve(const int &n) -> void {
    int m;
    cin >> m;
    vector<vector<pair<int, char> > > grid(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u--, v--;
        grid[u].emplace_back(v, c);
        grid[v].emplace_back(u, c);
    }

    for (auto &i: grid) {
        sort(all(i), [](pair<int, char> &a, pair<int, char> &b) {
            return a.second < b.second;
        });
    }

    vector<bool> vis(n);
    vi distn(n), prv(n, -1);
    vector<char> prvChar(n);
    queue<int> q;

    vis.assign(n, false);
    q.push(n - 1);
    vis[n - 1] = true;
    distn[n - 1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &i: grid[cur]) {
            if (!vis[i.first]) {
                distn[i.first] = distn[cur] + 1;
                vis[i.first] = true;
                q.push(i.first);
            }
        }
    }

    vis.assign(n, false);
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        vi v = {q.front()};
        q.pop();
        while (!q.empty() && distn[q.front()] == distn[v[0]]) {
            v.push_back(q.front());
            q.pop();
        }

        char mn = 'z' + 1;
        for (auto &cur: v) {
            for (auto &i: grid[cur]) {
                int v = i.first;
                if ((!vis[v] ||
                     vis[v] && i.second < prvChar[v]) &&
                    distn[v] == distn[cur] - 1) {
                    mn = min(mn, i.second);
                }
            }
        }

        for (auto &cur: v) {
            for (auto &i: grid[cur]) {
                int v = i.first;
                if ((!vis[v] ||
                     vis[v] && i.second < prvChar[v]) &&
                    distn[v] == distn[cur] - 1 &&
                    i.second == mn) {
                    prv[i.first] = cur;
                    prvChar[i.first] = i.second;
                    vis[i.first] = true;
                    q.push(i.first);
                }
            }
        }
    }

    vi path;
    string pathStr;
    int cur = n - 1;
    while (cur) {
        path.push_back(cur);
        pathStr.push_back(prvChar[cur]);
        cur = prv[cur];
    }
    path.push_back(0);

    reverse(all(path));
    reverse(all(pathStr));
    cout << path.size() - 1 << endl;
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] + 1 << " \n"[i == path.size() - 1];
    }
    cout << pathStr << endl;
}

bool solve_test(const int test_number) {
    int n = 1;
    // string n;
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
    cin >> test_cases;
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
