///https://cses.fi/problemset/task/1686/

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
const int N = 2e6+5;
vector<int>g[N],gt[N],gm[N];
int vis[N];
int arr[N];
int par[N];
int mx[N];
int temp[N];
int v[N];
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
int dfs3(int n)
{
    if(mx[n]!=-1)return mx[n];
    int val = 0;
    for(auto i:gm[n])
    {
        //cout<<i<<endl;
        val = max(val,dfs3(i));
    }
    //cout<<n<<" "<<v[n] + val<<endl;
    mx[n] = v[n] + val;
    return mx[n];
}
void solve()
{
    int n,m;cin>>n>>m;
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
    int cnt=0;
    for(auto i:st)
    {
        if(vis[i]==0)
        {
            cnt++;
            int sum=0;
            dfs2(i,cnt,sum);
            v[cnt] = sum;
            //cout<<cnt<<" "<<v[cnt]<<endl;
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
    for(int i=1;i<=cnt;i++)
    {
        mx[i] = -1;
    }
    int ans=0;
    for(int i=1;i<=cnt;i++)
    {
        if(mx[i]==-1)
        {
            dfs3(i);
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        ans = max(ans,mx[i]);
    }
    cout<<ans<<endl;
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
