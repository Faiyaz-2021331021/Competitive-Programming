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
const int N = 1e5+5;
vector<int>g[N];
int tin[N];
int low[N];
int vis[N];
int timer = 1;
vector<pair<int,int>>Bridge;
int ase=1;
void dfs(int n,int par)
{
    vis[n]=1;
    tin[n] = low[n] = timer;
    timer++;
    for(auto i:g[n])
    {
        if(i==par)continue;
        if(vis[i]==0)
        {
            dfs(i,n);
            low[n] = min(low[i],low[n]);
            if(low[i] > tin[n])
            {
                Bridge.pb({i,n});
            }
        }
        else
        {
            low[n] = min(low[n],low[i]);
        }
    }
}
void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,-1);
    for(auto i:Bridge)
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
        solve();
    }
}
