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

void preprocessing() {
}

typedef long double ld;
typedef complex<ld> Point;


// Cross product of OA and OB vectors
ld cross(const Point &O, const Point &A, const Point &B) { return imag((A - O) * conj(B - O)); }

// Dot product of vectors A and B
ld dot(const Point &A, const Point &B) { return real(A * conj(B)); }

// Circle-Line Intersection: returns intersection points
vector<Point> circleLine(const Point &c, ld r, const Point &a, const Point &b) {
    Point ab = b - a;
    ld ab2 = norm(ab);
    ld t = dot(ab, c - a) / ab2;
    Point p = a + ab * t;
    ld s2 = r * r - norm(c - p);
    if (s2 < -EPS) return {};
    if (abs(s2) < EPS) return {p};
    ld s = sqrt(s2);
    Point h = ab / abs(ab) * s;
    return {p - h, p + h};
}

// Cosine Rule: angle opposite to side a
ld cosRule(ld a, ld b, ld c) {
    ld res = (b * b + c * c - a * a) / (2 * b * c);
    return acos(max(-1.0L, min(1.0L, res)));
}

// Circle-Circle Intersection: returns number of intersections and sets res1, res2
int circleCircle(const Point &c1, ld r1, const Point &c2, ld r2, Point &res1, Point &res2) {
    Point d = c2 - c1;
    ld dist = abs(d);
    if (dist < EPS && abs(r1 - r2) < EPS) return INT32_MAX; // Infinite intersections
    if (dist > r1 + r2 + EPS || dist < abs(r1 - r2) - EPS) return 0; // No intersection
    ld a = (r1 * r1 - r2 * r2 + dist * dist) / (2 * dist);
    ld h2 = r1 * r1 - a * a;
    if (h2 < -EPS) return 0;
    ld h = h2 < EPS ? 0 : sqrt(h2);
    Point p = c1 + d * (a / dist);
    if (h == 0) {
        res1 = p;
        return 1;
    }
    Point offset = d * (h / dist) * Point(0, 1);
    res1 = p + offset;
    res2 = p - offset;
    return 2;
}

// Circle from Three Points: returns true if successful
bool circle3(const Point &p1, const Point &p2, const Point &p3, Point &cen, ld &r) {
    ld a = cross(p1, p2, p3);
    if (abs(a) < EPS) return false; // Collinear points
    cen = ((norm(p2) - norm(p1)) * Point(0, 1) - (norm(p3) - norm(p1)) * Point(1, 0)) / (2 * a) + p1;
    r = abs(cen - p1);
    return true;
}

// Point Position Relative to Circle: -1 inside, 0 outside, 1 on boundary
int circlePoint(const Point &cen, ld r, const Point &p) {
    ld dist2 = norm(p - cen), r2 = r * r;
    if (abs(dist2 - r2) < EPS) return 1;
    return (dist2 < r2) ? -1 : 0;
}

ld calculateIntersectionArea(ld R1, ld R2, ld x1, ld y1, ld x2, ld y2) {
    double d = sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    // Check if circles do not intersect
    if (d >= R1 + R2) {
        return 0.0;
    }
    if (d < fabs(R1 - R2)) {
        return 0.0;
    }

    if (d == fabs(R1 - R2)) {
        double R_min = std::min(R1, R2);
        return pi * R_min * R_min;
    }

    double theta1 = 2 * acos((d * d + R1 * R1 - R2 * R2) / (2 * d * R1));
    double theta2 = 2 * acos((d * d + R2 * R2 - R1 * R1) / (2 * d * R2));

    double area1 = 0.5 * R1 * R1 * (theta1 - sinl(theta1));
    double area2 = 0.5 * R2 * R2 * (theta2 - sinl(theta2));

    return area1 + area2;
}

auto Solve(const int &x1) -> double {
    int y1, r1, x2, y2, r2;
    cin >> y1 >> r1 >> x2 >> y2 >> r2;
    double Large = pi * max(r1, r2) * max(r1, r2);
    double ans = Large - calculateIntersectionArea(r1, r2, x1, y1, x2, y2);
    if (ans and ans != Large)
        return ans;

    return -1;
}

bool solve_test(const int test_number) {
    int n;
    cout << fixed << setprecision(20);
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
