#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

int n;

void setupIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int bfs(int x1, int y1, int x2, int y2, vector<vector<int>>& vis) {
    if (x1 == x2 && y1 == y2) return 0;  // Early exit if start is the target

    queue<pii> q;
    q.push({x1, y1});
    vis[x1][y1] = 1;

    int dx[] = {1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && vis[nx][ny] == 0) {
                vis[nx][ny] = vis[x][y] + 1;
                if (nx == x2 && ny == y2) {
                    return vis[nx][ny] - 1;
                }
                q.push({nx, ny});
            }
        }
    }
    return -1; // Target is unreachable
}

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Check if the start and target points are the same
    if (x1 == x2 && y1 == y2) {
        cout << 0 << endl;
        return; // Exit the function early
    }

    // Check for invalid coordinates
    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) {
        cout << "Invalid coordinates!" << endl;
        return;
    }

    vector<vector<int>> vis(n, vector<int>(n, 0));
    int result = bfs(x1, y1, x2, y2, vis);

    if (result == -1) {
        cout << "can't reach!" << endl;
    } else {
        cout << result << endl;
    }
}
int32_t main() {
    setupIO();
    int test_cases;
    cin >> test_cases >> n;
    while (test_cases--) {
        solve();
    }
    return 0;
}
