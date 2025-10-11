#include <bits/stdc++.h>
using namespace std;

void FILES() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

// وَقُلْ رَبِّ زِدْنِي عِلْمًا
#define ll long long

void solve() {
    ll x,y;
    cin>>x>>y;
    cout <<(gcd(x,y)==1?"GOOD":"NOT GOOD") <<endl;
}

signed main() {
    FILES();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}