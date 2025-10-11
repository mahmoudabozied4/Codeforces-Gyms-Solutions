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
template<typename treeType = long long, typename graphType = long long>
struct LCA {
    int N, LOG, ROOT;
    vector<vector<pair<int, graphType>>> adj;  // adj[u] = { {v, weight}, ... }
    vector<vector<int>>           anc;         // anc[u][j] = 2^j-th ancestor of u
    vector<vector<treeType>>      cost;        // cost[u][j] = merged edge-weights from u→anc[u][j]
    vector<int>                   depth;       // depth[u]
    vector<graphType>             dist;        // dist[u] = sum of weights from ROOT to u
    function<treeType(treeType, treeType)> operation;
    treeType neutral;

    // Constructor: you can pass `G` (adjacency) directly, or call init+addEdge later.
    LCA(
        int n = 0,
        const vector<vector<pair<int,graphType>>> &G = {},
        function<treeType(treeType, treeType)> op = [](treeType a, treeType b){ return a + b; },
        treeType _neutral = treeType(),
        int root = 1
    ) : N(n), ROOT(root), adj(G), operation(op), neutral(_neutral)
    {
        // If G is non-empty, copy it into adj[1..N], then build immediately.
        init(N);
        if (!G.empty()) {
            for (int u = 1; u <= N; u++) {
                for (auto &e : G[u]) {
                    // We assume G is already 1-based and undirected. If it isn't,
                    // make sure to call addEdge yourself instead of passing G here.
                    adj[u].push_back(e);
                }
            }
            build(ROOT);
        }
    }

    // (Re)initialize for n nodes. You must call build(root) before querying.
    void init(int n) {
        N = n;
        // Compute LOG = ceil(log2(n+1)) so that (1<<LOG) > N
        LOG = 1;
        while ((1 << LOG) <= N) LOG++;

        adj.assign(N + 1, {});
        anc.assign(N + 1, vector<int>(LOG, -1));
        cost.assign(N + 1, vector<treeType>(LOG, neutral));
        depth.assign(N + 1, 0);
        dist.assign(N + 1, 0);
        ROOT = 1;
    }

    // Add an undirected edge u<->v with weight w.
    // Nodes are assumed to be 1..N. If you use 0-based, shift accordingly.
    void addEdge(int u, int v, graphType w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Build the LCA tables, rooting the tree at `root`.
    // Fills anc[u][*], cost[u][*], depth[u], dist[u].
    // O(N log N).
    void build(int root = 1) {
        ROOT = root;
        // Reset depth, dist, anc, cost
        for (int u = 1; u <= N; u++) {
            depth[u] = 0;
            dist[u]  = 0;
            for (int j = 0; j < LOG; j++) {
                anc[u][j]  = -1;
                cost[u][j] = neutral;
            }
        }
        // Run DFS from root (parent = -1, depth = 0, initial edgeWeight = neutral)
        dfs(ROOT, -1, 0, neutral);

        // Build the upper levels of anc[][] and cost[][]
        for (int j = 1; j < LOG; j++) {
            for (int u = 1; u <= N; u++) {
                int mid = anc[u][j - 1];
                if (mid < 0) {
                    // If there's no 2^(j-1) ancestor, there's no 2^j ancestor either
                    anc[u][j]  = -1;
                    cost[u][j] = cost[u][j - 1];
                } else {
                    anc[u][j]  = anc[mid][j - 1];
                    cost[u][j] = operation(
                        cost[u][j - 1],
                        cost[mid][j - 1]
                    );
                }
            }
        }
    }

    // Return the k-th ancestor of u (or -1 if it doesn't exist). O(log N).
    int kthAncestor(int u, int k) const {
        if (u < 1 || u > N) return -1;
        if (depth[u] < k) return -1;
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                u = anc[u][j];
                if (u < 0) return -1;
            }
        }
        return u;
    }

    // Return the LCA of u and v in O(log N). Returns -1 if invalid.
    int get_lca(int u, int v) const {
        if (u < 1 || u > N || v < 1 || v > N) return -1;
        if (u == v) return u;
        // Ensure u is at least as deep as v
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        // Lift u up to match depth[v]
        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = anc[u][j];
                if (u < 0) return -1;
            }
        }
        if (u == v) return u;
        // Lift both until their ancestors diverge
        for (int j = LOG - 1; j >= 0; j--) {
            if (anc[u][j] != anc[v][j]) {
                u = anc[u][j];
                v = anc[v][j];
            }
        }
        // Now their parents are equal
        return anc[u][0];
    }

    // Return weighted distance (sum of weights) between u and v in O(log N).
    // If either is invalid or tree is disconnected, returns -1.
    graphType distance(int u, int v) const {
        int w = get_lca(u, v);
        if (w < 0) return -1;
        return depth[u] + depth[v] - 2 * depth[w];
    }

    // Return the "merge" of edge‐weights on the path from u up exactly k steps.
    // That is, if k = 3, it merges edge(u->anc[u][0]), edge(anc[u][0]->anc[u][1]), edge(anc[u][1]->anc[u][2]).
    // O(log N). Returns `neutral` if depth[u] < k.
    treeType get_cost(int u, int k) const {
        if (u < 1 || u > N) return neutral;
        if (depth[u] < k) return neutral;
        treeType ret = neutral;
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                ret = operation(ret, cost[u][j]);
                u = anc[u][j];
                if (u < 0) break;
            }
        }
        return ret;
    }

    // Query the merged result of edge‐weights on the entire path u→v (commutative op).
    // O(log N).
    treeType query(int u, int v) const {
        int w = get_lca(u, v);
        if (w < 0) return neutral;
        // Merge edges on u→w
        treeType leftMerge  = get_cost(u, depth[u] - depth[w]);
        // Merge edges on v→w
        treeType rightMerge = get_cost(v, depth[v] - depth[w]);
        return operation(leftMerge, rightMerge);
    }

    bool is_on_path(int u , int v , int w) {
        return  distance(u , v) == distance(u , w) + distance(w , v);
    }

private:
    // DFS to set anc[u][0], cost[u][0], depth[u], dist[u].
    // Parameters:
    //   u         : current node
    //   p         : parent of u (or -1 if u is root)
    //   d         : depth of u
    //   edgeCost  : weight of edge (p->u), or neutral if u is root
    void dfs(int u, int p, int d, treeType edgeCost) {
        anc[u][0]   = p;
        cost[u][0]  = edgeCost;    // this is the “merge value” for the single edge from p->u
        depth[u]    = d;

        // If we want to maintain a separate dist[] for "sum of weights from root",
        // cast edgeCost back to graphType (assuming that's how the user wants).
        if (p < 0) dist[u] = 0;
        else         dist[u] = dist[p] + static_cast<graphType>(edgeCost);

        for (auto &ed : adj[u]) {
            int v      = ed.first;
            graphType w = ed.second;
            if (v == p) continue;
            dfs(v, u, d + 1, static_cast<treeType>(w));
        }
    }
};

LCA lca;
auto Solve(const int &n) {
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    lca.init(n);
    for (int i = 0; i < n - 1; ++i) {
        int u , v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
        lca.addEdge(u + 1 , v + 1 , 0);
    }
    lca.build(1);
    int u = 0, v = 1 , w = 1;
    for (int i = 2; i < n; ++i) {
        if (lca.is_on_path(u + 1, i + 1, v + 1))
            v = i;
        else if (lca.is_on_path(v + 1 , i + 1, u + 1))
            u = i;
        else if(!lca.is_on_path(u + 1, v + 1, i + 1))
            break;
        w = i;
    }
    cout << w + 1 << ' ';
    for (int i = 2; i < n; ++i) {
        if(i <= deg[0])
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
    // thx Homz
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
