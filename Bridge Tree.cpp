///https://codeforces.com/contest/1000/problem/E


#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define debug           cout<<"HERE"<<endl;
#define ff              first
#define ss              second
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 3e5+5;
vector<int>g[N];
int tin[N],low[N],vis[N];
int timer = 1;
void dfs(int n, int par=0)
{
    vis[n] = 1;
    tin[n] = low[n] = timer++;
    for(auto i:g[n])
    {
        if(i==par)continue;
        if(vis[i]==0)
        {
            dfs(i,n);
            low[n] = min(low[i],low[n]);
        }
        else
        {
            low[n] = min(low[n],tin[i]);
        }
    }
}
 
vector<int> bt[N];
void make_tree(int u, int par = 0)
{
    vis[u] = 1;
    if(low[u] == tin[u])
    {
        int v = ++timer;
        if(par != 0) bt[par].push_back(v), bt[v].push_back(par);
        par = v;
    }
    for(auto v: g[u]) if(!vis[v]) make_tree(v, par);
}
int dep[N];
int diameter(int u, int par = 0, int d = 0)
{
    dep[u] = d;
    int ans = u;
    for(auto v: bt[u]) if(v != par)
    {
        int nw = diameter(v, u, d + 1);
        if(dep[nw] > dep[ans]) ans = nw;
    }
    return ans;
}
void solve()
{
    int n, m;
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++)vis[i]=0;
    timer = 0; make_tree(1);
    cout << dep[diameter(diameter(1))] << '\n';
}
int32_t main()
{
    edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}
