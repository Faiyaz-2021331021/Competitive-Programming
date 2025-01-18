///https://www.spoj.com/problems/GOODA/

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
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
const int N = 2e6+5;
vector<int>g[N],gt[N],gm[N];
int vis[N];
int arr[N];
int par[N];
void dfs1(int n,vector<int>&s)
{
    vis[n]=1;
    for(auto i:g[n])
    {
        if(vis[i]==0)
        {
            dfs1(i,s);
        }
    }
    s.pb(n);
}
void dfs2(int &n,int &who,int &sum)
{
    vis[n]=1;
    par[n]=who;
    sum+=arr[n];
    for(auto i:gt[n])
    {
        if(vis[i]==0)
        {
            dfs2(i,who,sum);
        }
    }
}
void solve()
{
    int n,m,s,t;cin>>n>>m>>s>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        par[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        g[a].pb(b);
        gt[b].pb(a);
    }
    vector<int>st;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)dfs1(i,st);
    }
    for(int i=1;i<=n;i++)vis[i]=0;
    reverse(st.begin(),st.end());
    vector<int>v(n+1,0);
    int cnt=0;
    for(auto i:st)
    {
        if(vis[i]==0)
        {

            cnt++;
            int sum=0;
            dfs2(i,i,sum);
            v[i] = sum;
            //cout<<i<<" "<<par[i]<<endl;
        }
    }
    for(int i=1;i<=n;i++)gt[i].clear();
    for(int i=1;i<=n;i++)
    {
        //cout<<v[i]<<endl;
        for(auto j:g[i])
        {
            if(par[j]!=par[i])
            {
                gm[par[i]].pb(par[j]);
            }
        }
    }
    priority_queue<pair<int,int>>p;
    p.push({par[s],v[par[s]]});
    vector<int>dist(n+1,0);
    dist[par[s]] = v[par[s]];
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<par[i]<<endl;
    // }
    // for(int i=1;i<=n;i++)
    // {
    //     for(auto j:gt[i])cout<<j<<" ";
    //         cout<<endl;
    // }
    while (!p.empty())
    {
        auto node = p.top();
        p.pop();
        int curr = node.first; 
        for (auto next : gm[curr])
        {
            if (dist[next] < dist[curr] + v[next])
            {
                dist[next] = dist[curr] + v[next];
                p.push({next, dist[next]});
            }
        }
    }
    cout<<dist[par[t]];
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
