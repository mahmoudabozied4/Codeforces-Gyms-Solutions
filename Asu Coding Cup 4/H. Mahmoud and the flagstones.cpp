#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define lol long long int
#define endl '\n'
#define elif else if
#define endd(s) return void(cout << s << "\n")
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define fr first
#define sc second
#define X first
#define Y second
#define fixed(n) fixed << setprecision(n)
#define sz(s) int32_t(s.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define getline(s) getline(cin >> ws, s)
#define kill return 0
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define pi  3.14159
#define all(vec) vec.begin(), vec.end()
#define rall(v) v.rbegin(),v.rend()
#define mul_mod(a, b) (((a % M) * (b % M)) % M)
#define add_mod(a, b) (((a % M) + (b % M)) % M)
typedef pair<int , int> pii;
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
const int N = 100005 , M = 1e9 + 7 , OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9;
vector < string > RET = {"No", "Yes"};

void Zied(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

template<typename T = int> istream& operator >>(istream& in, vector<T>& v) {
    for (auto& x : v)
        in >> x;
    return in;
}
template<typename T = int> ostream& operator <<(ostream& out, const vector<T>& v) {
    for (const T& x : v)
        out << x << ' ';
    return out;
}

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};
char di[] = {'D', 'L', 'U', 'R'};

void preprocessing(){

}
int fp (int b  , int p){
    if( p == 0 ) return 1;
    if (p == 1) return b % M;
    int ret = fp(b , p / 2);
    if (p % 2) return  (ret * ret)% M * b % M ;
    return (ret * ret)% M  ;
}
void Solve() {
    int n;cin >> n;
    set<int> st;
    vector < int > v(N);
    for (int i = 0; i < n; ++i) {
        int x ; cin >> x;
        st.insert(x);
        v[x]++;
    }
    int sum = 0 ;
    for (auto it : st) {
        sum += fp(2 , v[it]) - 1;
    }
    cout << sum << endl;
}


int32_t main() {
    Zied();
    preprocessing();
    int test_cases = 1;
//    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        //        cout << "Case #" << tc << ": ";
        Solve();
//                cout << endl;
    }
    kill;
    //    Time
}
/*
                ,     :     ,
           '.    ;    :    ;    ,`
     '-.  `.  `-.._ .:. _..-'  ,'
  ,     '-. .:  __     __  :.-' ,
  :  :    ,  ,-'"  `. .  `"-.  ,    ;  ;
  '  `._ ,-'" `"-.  .-".  .-"` "-._ ,'  ,'
        `:.   `.  `. -  `-'  ,'  , :    ,'
  ,    .      `.  `. -  `-'  ,'  , :  '    .
       ;  `,   `.  `-..__.,-' ,  ,` '    ;
   ` . :   `,.  `-..__,,..-' ,'  ,    :    ` .
       ` .   `-.__,,..-'   ,    ,   :    ` .

*/