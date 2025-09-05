/// https://atcoder.jp/contests/dp/tasks/dp_g


#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n) 
#define arsort(a,n)      sort(a,a+n,greater<int>()) 
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" ";
#define vcout(v)        for(auto i:v)cout<<i<<" ";
#define vsort(v)        sort(v.begin(),v.end())
#define vrsort(v)       sort(v.rbegin(),v.rend());
#define YES             cout<<"YES"<<endl
#define NO              cout<<"NO"<<endl
#define yes             cout<<"yes"<<endl
#define no              cout<<"no"<<endl
#define Yes             cout<<"Yes"<<endl
#define No              cout<<"No"<<endl
#define pqr             priority_queue<int,vector<int>,greater<int>>
#define debug           cout<<"HERE"<<endl;  
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 2e5;
vector<int>g[N];int vis[N];int dp[N];
void dfs(int n)
{
    vis[n]=1;dp[n]=0;
    for(auto i:g[n])
    {
        if(vis[i]==0)
        {
            dfs(i);vis[i]=1;
        }
        dp[n] = max(1+dp[i],dp[n]);
    }
}
void solve()
{
    int n,m;cin>>n>>m;
    while(m--)
    {
        int a,b;cin>>a>>b;
        g[a].pb(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)dfs(i);
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        mx = max(mx,dp[i]);
    }
    cout<<mx<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": "<<endl;
        solve();
    }
} 
