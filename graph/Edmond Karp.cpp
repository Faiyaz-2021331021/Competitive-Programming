///https://cses.fi/problemset/task/1695/

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
const int N = 505;
vector<pair<int,int>>g[N];
int cap[N][N];
int orcap[N][N];
int bfs(int s,int t,vector<int>&parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int,int>> q;
    q.push({s,1e18});
    while(!q.empty())
    {
        int cur = q.front().ff;
        int flow = q.front().ss;
        q.pop();
 
        for(auto i:g[cur])
        {
            int next = i.ff;
            if (parent[next] == -1 && cap[cur][next] > 0)
            {
                parent[next] = cur;
                int nf = min(flow, cap[cur][next]);
                if(next == t)
                {
                    return nf;
                }
                q.push({i.ff,nf});
            }
        }
    }
    return 0;
}
int maxflow(int s,int t,int n)
{
    int flow = 0;
    vector<int>parent(n+5);
    int nf;
    while(nf = bfs(s,t,parent))
    {
        flow+=nf;
        int cur = t;
        while(cur != s)
        {
            int prev = parent[cur];
            cap[prev][cur] -= nf;
            cap[cur][prev] += nf;
            cur = prev;
        }
    }
    return flow;
}
void solve()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;cin>>a>>b;
        c = 1;
        g[a].pb({b,c});
        g[b].pb({a,c});
        cap[a][b] += c;
        cap[b][a] += c;
        orcap[a][b] += c;
        orcap[b][a] += c;
    }
    vector<int>par(n+1,-1);
    int ans = maxflow(1,n,n+1);
    cout<<ans<<endl;
    vector<int>vis(n+5,0);
    queue<int>q;
    q.push(1);
    vis[1]=1;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(auto i:g[u])
        {
            if(vis[i.ff]==0 &&  cap[u][i.ff] > 0)
            {
                vis[i.ff] = 1;
                q.push(i.ff);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1)
        {
            for(auto v : g[i])
            {
                int j = v.ff;
                if(vis[j]==0 && orcap[i][j] > 0)
                    cout << i << " " << j << endl;
            }
        }
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
