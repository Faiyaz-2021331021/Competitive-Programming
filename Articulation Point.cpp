///https://vjudge.net/contest/688961#problem/H


#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define debug           cout<<"HERE"<<endl;
#define ff              first
#define ss              second
#define ppr             pair<int,pair<int,int>>
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
int arti[N];
int timer = 1;
void dfs(int n,int par)
{
    vis[n] = 1;
    tin[n] = low[n] = timer;
    timer++;
    int ch=0;
    for(auto i:g[n])
    {
        if(vis[i]==0)
        {
            dfs(i,n);
            low[n] = min(low[n],low[i]);
            if(low[i] >= tin[n] && par!=-1)
            {
                arti[n] = 1;
            }
            ch++;
        }
        else
        {
            low[n] = min(low[n],tin[i]);
        }
    }
    if(ch>1 && par==-1)
    {
        arti[n]=1;
    }
}
void solve(int &n,int &m)
{
    for (int i =0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    timer=1;
    dfs(1,-1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(arti[i])ans++;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        vis[i]=0;
        tin[i]=0;
        low[i]=0;
        arti[i]=0;
    }
}
int32_t main()
{
    edm();
    int t = 1;
    //cin>>t;
    while(1)
    {
        int n,m;cin>>n>>m;
        if(n==0 && m==0)return 0;
        solve(n,m);
    }
}
