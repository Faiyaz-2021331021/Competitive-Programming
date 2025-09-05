////https://codeforces.com/contest/427/problem/C

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define debug           cout<<"HERE"<<endl;
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 1e5+5;
vector<int>g[N],gt[N];
int vis[N];
int arr[N];
const int mod = 1e9+7;
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
void dfs2(int n,int &mn,int &cnt)
{
    vis[n]=1;
    if(arr[n]==mn)
    {
        cnt++;
        cnt = cnt%mod;
    }
    else if(arr[n]<mn)
    {
        mn = arr[n];
        cnt = 1;
    }
    for(auto i:gt[n])
    {
        if(vis[i]==0)
        {
            dfs2(i,mn,cnt);
        }
    }
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    int m;cin>>m;
    while(m--)
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
    int ans=0,koyta=1;
    reverse(st.begin(),st.end());
    for(auto i:st)
    {
        if(vis[i]==0)
        {
            int mn=1e18,cnt=0;
            dfs2(i,mn,cnt);
            ans+=mn;
            koyta = (koyta*cnt)%mod;
            //cout<<mn<<" "<<cnt<<endl;
        }
    }
    cout<<ans<<" "<<koyta%mod<<endl;
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
