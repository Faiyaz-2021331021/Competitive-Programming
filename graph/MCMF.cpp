//Min Cost Max Flow
//https://cses.fi/problemset/task/2129/

#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define endl           '\n'
#define debug          cout<<"here"<<endl
#define ff             first
#define ss             second
// #define pr             pair<int,int>
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outputA.txt","w",stdout);
    #endif
}
struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;
const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> &edges, int K, int s, int t, vector<pair<int,int>> &matchings)
{
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));

    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int totalCost = 0;
    vector<int> d, p;

    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }
        flow += f;
        totalCost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    int n = (N - 2) / 2;
    for (int i = 1; i <= n; i++) {
        for (int v : adj[i]) {
            if (v >= n + 1 && v <= n + n && capacity[v][i] > 0) {
                matchings.push_back({i, v - n});
            }
        }
    }

    if (flow < K)
        return -1;
    else
        return totalCost;
}
void solve()
{
    int n;cin>>n;
    vector<Edge>edges;
    for(int i=1;i<=n;i++)
    {
        edges.pb({0,i,1,0});
        for(int j=1;j<=n;j++)
        {
            int a;cin>>a;
            edges.pb({i,n+j,1,a});
        }
    }
    for(int j=1;j<=n;j++)
    {
        edges.pb({n+j,n+n+1,1,0});
    }
    int src = n+n+1;
    vector<pair<int,int>>mt;
    int ans = min_cost_flow(n+n+2,edges,n,0,src,mt);
    cout<<ans<<endl;
    for(auto i:mt)
    {
        cout<<i.ff<<" "<<i.ss<<endl;
    }
}
int32_t main()
{
    edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}




