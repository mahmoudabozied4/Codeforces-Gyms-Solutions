#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

int dijkstra(int start, int end, const vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.to, w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[end];
}

int tsp(int mask, int pos, vector<vector<int>>& dp, const vector<vector<int>>& dist, int targetMask) {
    if (mask == targetMask) return dist[pos][dist.size() - 1];
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int i = 0; i < dist.size(); i++) {
        if (!(mask & (1 << i))) {
            ans = min(ans, dist[pos][i] + tsp(mask | (1 << i), i, dp, dist, targetMask));
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M, F;
        cin >> N >> M >> F;

        vector<vector<Edge>> graph(N + 1);
        for (int i = 0; i < M; i++) {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            graph[X].push_back({Y, Z});
            graph[Y].push_back({X, Z});
        }

        vector<int> friends(F);
        for (int i = 0; i < F; i++) {
            cin >> friends[i];
        }

        vector<int> nodes = {1};
        nodes.insert(nodes.end(), friends.begin(), friends.end());
        nodes.push_back(N);

        int K = nodes.size();
        vector<vector<int>> dist(K, vector<int>(K));
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                dist[i][j] = dijkstra(nodes[i], nodes[j], graph);
            }
        }

        vector<vector<int>> dp(1 << K, vector<int>(K, -1));
        int targetMask = (1 << K) - 1;
        int answer = tsp(1, 0, dp, dist, targetMask);

        cout << "Case " << t << ": " << answer << "\n";
    }
    return 0;
}
