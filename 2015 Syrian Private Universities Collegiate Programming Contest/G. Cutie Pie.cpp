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
    ll n, m;
    cin >> n >> m;
    char grid[n + 1][m + 1];
    for (ll i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j + 2 < m) {
                if (grid[i][j] == 'p' && grid[i][j + 1] == 'i' && grid[i][j + 2] == 'e') {
                    cout << "Cutie Pie!" << '\n';
                    return;
                }
            }
            if (i + 2 < n) {
                if (grid[i][j] == 'p' && grid[i + 1][j] == 'i' && grid[i + 2][j] == 'e') {
                    cout << "Cutie Pie!" << '\n';
                    return;
                }
            }
            if (i + 2 < n && j - 2 >= 0) {
                if (grid[i][j] == 'p' && grid[i + 1][j - 1] == 'i' && grid[i + 2][j - 2] == 'e') {
                    cout << "Cutie Pie!" << '\n';
                    return;
                }
            }
            if (i + 2 < n && j + 2 < m) {
                if (grid[i][j] == 'p' && grid[i + 1][j + 1] == 'i' && grid[i + 2][j + 2] == 'e') {
                    cout << "Cutie Pie!" << '\n';
                    return;
                }
            }
            if (j-2 >= 0) {
                if (grid[i][j] == 'p' && grid[i][j - 1] == 'i' && grid[i][j - 2] == 'e') {
                    cout << "Cutie Pie!" << '\n';
                    return;
                }
            }
            if (i-2 >= 0) {
                if (grid[i][j] == 'p' && grid[i-1][j] == 'i' && grid[i-2][j] == 'e') {
                    cout << "Cutie Pie!" << '\n';
                    return;
                }
            }
            if (i-2 >= 0 && j+2<m) {
                if (grid[i][j] == 'p' && grid[i-1][j+1] == 'i' && grid[i-2][j+2] == 'e') {
                    cout << "Cutie Pie!" << '\n';
                    return;
                }
            }
            if (i-2 >= 0 && j-2 >= 0) {
                if (grid[i][j] == 'p' && grid[i-1][j-1] == 'i' && grid[i-2][j-2] == 'e') {
                    cout << "Cutie Pie!" << '\n';
                    return;
                }
            }
        }
    }
    cout << "Sorry Man" << '\n';
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