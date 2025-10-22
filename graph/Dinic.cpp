///https://cses.fi/problemset/task/1695

#include<bits/stdc++.h>
using namespace std;
#define int            int
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
const int N = 5010;
struct Dinic
{
    struct Edge
    {
        int to, rev;
        int cap, flow;
        int id;
    };
    int n, s, t;
    vector<vector<Edge>> g;
    vector<int> level, ptr;
    Dinic(int _n) : n(_n)
    {
        g.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void add_edge(int u, int v, int w, int id=-1)
    {
        Edge a = {v, (int)g[v].size(), w, 0, id};
        Edge b = {u, (int)g[u].size(), 0, 0, -2};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    bool bfs()
    {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            for(auto &e : g[u])
            {
                if(level[e.to] == -1 && e.flow < e.cap)
                {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int pushed)
    {
        if(u == t) return pushed;
        for(int &i = ptr[u]; i < g[u].size(); i++)
        {
            auto &e = g[u][i];
            if(level[e.to] == level[u]+1 && e.flow < e.cap)
            {
                int tr = dfs(e.to, min(pushed, e.cap - e.flow));
                if(tr > 0)
                {
                    e.flow += tr;
                    g[e.to][e.rev].flow -= tr;
                    return tr;
                }
            }
        }
        return 0;
    }

    int max_flow(int _s, int _t)
    {
        s = _s; t = _t;
        int flow = 0;
        while(bfs())
        {
            fill(ptr.begin(), ptr.end(), 0);
            while(int pushed = dfs(s, 1e9)) flow += pushed;
        }
        return flow;
    }

    void min_cut_edges(vector<pair<int,int>>& cut_edges)
    {
        vector<bool> reachable(n, false);
        queue<int> q;
        q.push(s);
        reachable[s] = true;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &e : g[u]) {
                if(e.flow < e.cap && !reachable[e.to])
                {
                    reachable[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        for(int u = 0; u < n; u++)
        {
            if(!reachable[u]) continue;
            for(auto &e : g[u]) {
                if(!reachable[e.to] && e.cap > 0) 
                {
                    cut_edges.push_back({u, e.to});
                }
            }
        }
    }
};
int chk(int n)
{
    int low=1,high=n-1;
    int val=0;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int koto = mid*mid;
        if(koto<=n)
        {
            val=mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    if(val*val==n)
    {
        return 1;
    }
    return 0;
}
void solve()
{
    int n,m;cin>>n>>m;
    Dinic F(n + 1);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        F.add_edge(a,b,1);
        F.add_edge(b,a,1);
    }
    int ans = F.max_flow(1,n);
    cout<<ans<<endl;
    vector<pair<int,int>>v;
    F.min_cut_edges(v);
    for(auto i:v)
    {
        cout<<i.ff<<" "<<i.ss<<endl;
    }
}
int32_t main()
{
    edm();
    int t = 1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}




