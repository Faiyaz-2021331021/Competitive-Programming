///https://codeforces.com/contest/1324/problem/F

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n) 
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" ";
#define vcout(v)        for(auto i:v)cout<<i<<endl;
#define vsort(v)        sort(v.begin()+1,v.end())
#define vrsort(v)       sort(v.rbegin()+1,v.rend());
#define YES             cout<<"YES"<<endl
#define NO              cout<<"NO"<<endl
#define yes             cout<<"yes"<<endl
#define no              cout<<"no"<<endl
#define Yes             cout<<"Yes"<<endl
#define No              cout<<"No"<<endl
#define pqr             priority_queue<int,vector<int>,greater<int>>
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
const int N = 200005;
int vis[N];
int val[N];
int par[N];
int bw[N];
vector<int>arr[N];
int dfs(int n)
{
    vis[n]=1;
    for(auto i:arr[n])
    {
        if(vis[i]==0)
        {
            par[i]=n;
            val[n] += max(0ll,dfs(i));
        }
    }
    val[n]+=bw[n];
    return max(0ll,val[n]);
}
void rerooting(int n)
{
    vis[n]=1;
    for(auto i:arr[n])
    {
        if(vis[i]==0)
        {
            if(val[i]>=0)
            {
                val[i]=max(val[i],val[n]);
            }
            else val[i]=val[n]-1;
            val[i]=max(val[i],bw[i]);
            rerooting(i);
        }
    }
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        if(a)a=1;
        else a=-1;
        bw[i]=a;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        //cout<<val[i]<<endl;
    }
    rerooting(1); 
    for(int i=1;i<=n;i++)
    {
        cout<<max(bw[i],val[i])<<" ";
    }
    cout<<endl;
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
