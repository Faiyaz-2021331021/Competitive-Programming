#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hopcroft-Karp Template for Maximum Bipartite Matching
// 1-indexed for both left (U) and right (V) sets.
struct HopcroftKarp {
    int n, m; // n = size of left set U, m = size of right set V
    vector<vector<int>> adj;
    vector<int> matchU, matchV, dist;
    const int INF = 1e9;

    HopcroftKarp(int n, int m) : n(n), m(m), adj(n + 1), matchU(n + 1, 0), matchV(m + 1, 0), dist(n + 1, 0) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (matchU[u] == 0) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INF;
            }
        }
        dist[0] = INF; // dist[0] tracks the shortest path to an unmatched right node
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            if (dist[u] < dist[0]) {
                for (int v : adj[u]) {
                    if (dist[matchV[v]] == INF) {
                        dist[matchV[v]] = dist[u] + 1;
                        q.push(matchV[v]);
                    }
                }
            }
        }
        return dist[0] != INF;
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u]) {
                if (dist[matchV[v]] == dist[u] + 1) {
                    if (dfs(matchV[v])) {
                        matchV[v] = u;
                        matchU[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INF; // Prune dead ends
            return false;
        }
        return true;
    }

    int max_matching() {
        int matching = 0;
        while (bfs()) {
            for (int u = 1; u <= n; u++) {
                if (matchU[u] == 0 && dfs(u)) {
                    matching++;
                }
            }
        }
        return matching;
    }
};

void solve() {
    int n, k; 
    // n = grid size (n x n), k = number of asteroids
    if (!(cin >> n >> k)) return;

    // Left side = Rows (1 to n), Right side = Columns (1 to n)
    HopcroftKarp hk(n, n);

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        // Edge between Row r and Column c represents an asteroid at (r, c)
        hk.add_edge(r, c); 
    }

    // Minimum Vertex Cover == Maximum Bipartite Matching
    int min_lasers = hk.max_matching();
    
    cout << min_lasers << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
