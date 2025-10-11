#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
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
const int N = 2e4, M = 1e9 + 7, OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9, pi = 3.141592653589793;
#define kill return 0
vector<string> RET = {"NO", "YES"};
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


template<class T>
struct Math {
    T mod;
    vector<bool> prime;
    vector<T> fact, primes, mx_prime;

    Math() {
        mod = 1e9 + 7;
        fact = vector<T>(0);
        prime = vector<bool>(0);
        primes = vector<T>(0);
    }

    Math(T m) {
        mod = m;
        fact = vector<T>(0);
        prime = vector<bool>(0);
        primes = vector<T>(0);
        mx_prime = vector<T>(0);
    }

    void generate_fact(int n) {
        fact.assign(n + 5, 1);
        for (int i = 1; i <= n; ++i)
            fact[i] = mult(fact[i - 1], i);
    }

    // Generate all prime numbers

    void Sieve(int n) {
        prime.assign(n + 1, true);
        mx_prime.assign(n + 5, 0);
        prime[0] = prime[1] = false;

        for (int i = 2; 1LL * i * i <= n; ++i) {
            if (!prime[i]) continue;
            mx_prime[i] = i; // Mark i as its own highest prime factor
            for (int j = 2; 1LL * j * i <= n; ++j) {
                prime[1LL * i * j] = false;
                if (mx_prime[i * j] == 0) mx_prime[i * j] = i; // Fix: mark i*j, not j
            }
        }

        // Ensure all primes have themselves as their highest prime factor
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                primes.push_back(i);
                if (mx_prime[i] == 0) mx_prime[i] = i;
            }
        }
    }

    // Requires Sieve
    auto prime_factorizationS(int n) {
        vector<int> primes;
        while (n > 1) {
            int p = mx_prime[n];
            if (p == 0) {
                // n is prime itself
                p = n; // use n as the prime factor
            }
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                primes.push_back(p);
            }
        }
        return primes;
    }

    auto prime_factorization(int n) {
        vector<pii> factors;

        if (n < 2) return factors;

        int cnt = 0;
        while (!(n % 2)) {
            cnt++;
            n /= 2;
        }
        if (cnt) factors.push_back({2, cnt});

        for (ll i = 3; i * i <= n; i += 2) {
            int cnt = 0;
            while (!(n % i)) {
                cnt++;
                n /= i;
            }
            if (cnt) factors.push_back({i, cnt});
        }

        if (n > 1) factors.push_back({n, 1});

        return factors;
    }

    bool isPrime(T n) {
        if (n == 2) return true;
        if (n % 2 == 0 || n < 2) return false;
        bool res = true;
        for (int i = 3; 1LL * i * i <= n; i += 2) if (!(n % i)) res = false;
        return res;
    }

    // Requires Sieve
    T countDivisors(T x) {
        T res = 1;
        for (T p: primes) {
            if (1LL * p * p > x) break;
            if (x % p) continue;
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                ++cnt;
            }
            res *= cnt + 1;
        }

        if (x > 1) res *= 2;

        return res % mod;
    }

    T add(T a, T b) {
        T res = a + b;
        if (res < 0) res += mod;
        if (res >= mod) res -= mod;
        return res;
    }

    T mult(T a, T b) {
        return 1LL * (a % mod) * (b % mod) % mod;
    }

    T power(T a, T b) {
        if (b == 0) return 1;
        if (b < 0) return power(inverse(a), -b);
        T ret = power(mult(a, a), b / 2);
        if (b % 2) ret = mult(ret, a);
        return ret;
    }

    T div_mod(T a, T b) {
        return a * 1LL * inverse(b) % mod;
    }

    T inverse(T b) {
        return power(b, mod - 2);
    }

    T GCD(T a, T b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    T LCM(T a, T b) {
        return a / GCD(a, b) * b;
    }

    // Requires generate_factorial
    T nCr(T n, T r) {
        return mult(mult(fact[n], inverse(fact[n - r])), inverse(fact[r]));
    }

    T nPr(T n, T k) {
        return mult(fact[n], inverse(fact[n - k]));
    }

    T big_int_mod(string &num, T a) {
        T res = 0;
        for (char c: num)
            res = (1LL * res * 10 + c - '0') % a;
        return res;
    }

    T is_perfect_square(int n) {
        ll sq = sqrt(n);
        return sq * sq == n;
    }
};

Math<int> m;

void preprocessing() {
}

void Solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;

    int mn = OO;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 1 ) {
            mn = min(mn , v[i]) ;
        }
        sum += v[i];
    }

    if (sum % 2 == 0)
        cout << sum;
    else
        cout << sum - mn;
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