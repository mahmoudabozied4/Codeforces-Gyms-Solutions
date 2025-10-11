#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define ll long long
#define ld long double
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
const int N = 2e4, M = 1e9 + 7, OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9, pi = 3.141592653589793;
#define kill return 0
vector<string> RET = {"No", "Yes"};
#define IO(NAME) \
cin.tie(0)->sync_with_stdio(0); \
if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
freopen(NAME ".out","w",stdout);

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

enum dir { d, r, u, l, ul, dr, ur, dl };

int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};


void preprocessing() {
}

struct point {
    ld x, y;
    point() { x = y = 0; }

    point(ld x, ld y) : x(x), y(y) {
    }

    point operator-(point other) const {
        point ret(x - other.x, y - other.y);
        return ret;
    }

    point operator+(point other) const {
        point ret(x + other.x, y + other.y);
        return ret;
    }
};

auto crp(point A, point B) {
    // Cross Product
    return A.x * B.y - A.y * B.x;
}

ld orientation(point A, point B, point C) {
    int val = crp(B - A, C - A);
    if (val > 0) return 1; // Left, Counter Clockwise
    if (val < 0) return -1; // Right, Clockwise
    return 0; // Same Line
}

int double_area_of_tri(point A, point B, point C) {
    return fabs(crp(B - A, C - A));
}

int double_area_of_polygon(vector<point> &poly) {
    // poly must be Ordered
    int ret = 0;
    for (int i = 0; i < sz(poly); i++) {
        point nxt = poly[(i + 1) % sz(poly)];
        ret += crp(poly[i], nxt);
    }
    return ret;
}

bool point_on_segment(point P, point A, point B) {
    // point P on the Line AB
    int o = orientation(P, A, B);
    if (o == 0 and P.x >= min(A.x, B.x) and P.x <= max(A.x, B.x)
        and P.y >= min(A.y, B.y) and P.y <= max(A.y, B.y))
        return true;
    return false;
}

int point_vs_poly(point P, vector<point> &poly) {
    // Convex Polygon
    // 0 : on Boundary
    // 1 : inside
    // 2 : outside
    for (int i = 0; i < sz(poly); i++) {
        if (point_on_segment(P, poly[i], poly[(i + 1) % sz(poly)]))return 1;
    }
    for (int i = 0; i < sz(poly); i++) {
        point a = poly[i];
        point b = poly[(i + 1) % sz(poly)];
        point c = poly[(i + 2) % sz(poly)];
        if (orientation(a, b, c) != orientation(a, b, P))return 2;
    }
    return 0;
}

auto dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

auto dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


void Solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i >= sz(v[0])) flag = false;
        if (v[0][i] != v[i][0]) flag = false;
    }
    if (sz(v[0]) != n) flag = false;
    cout << RET[flag] << endl;
}

int32_t main() {
    Zied();
    preprocessing();
    int test_cases = 1;
    // cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        //        cout << "Case #" << tc << ": ";
        Solve();
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
