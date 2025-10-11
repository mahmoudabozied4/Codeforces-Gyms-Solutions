#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define endl '\n'

void Zied() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

ll cross(pii a, pii b) {
    return a.first * b.second - a.second * b.first;
}

double area(vector<pii> &fig) {
    ll res = 0;
    for (size_t i = 0; i < fig.size(); i++) {
        pii p = i ? fig[i - 1] : fig.back();
        pii q = fig[i];
        res += cross(p, q);
    }
    return fabs(res) / 2.0;
}

void Solve() {
    int N;
    cin >> N;
    if (N < 1 || N > 1000) return; // Validate N
    double total_area = 0;
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        if (P < 3 || P > 50) return; // Validate P
        vector<pii> points(P);
        for (int j = 0; j < P; j++) {
            cin >> points[j].first >> points[j].second;
            if (points[j].first < 0 || points[j].first > 1000000 ||
                points[j].second < 0 || points[j].second > 1000000) return; // Validate coordinates
        }
        total_area += area(points);
    }
    cout << static_cast<ll>(floor(total_area)) << endl;
}

int main() {
    Zied();
    Solve();
    return 0;
}