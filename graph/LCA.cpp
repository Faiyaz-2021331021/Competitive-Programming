#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define endl           '\n'
#define pp             pair<int,pair<int,int>>
#define asort(a,n)     sort(a,a+n) 
#define vsort(v)       sort(v.begin(),v.end())
#define vrsort(v)      sort(v.rbegin(),v.rend());
#define YES            cout<<"YES"<<endl
#define NO             cout<<"NO"<<endl
#define yes            cout<<"yes"<<endl
#define no             cout<<"no"<<endl
#define Yes            cout<<"Yes"<<endl
#define No             cout<<"No"<<endl
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 999999;
const int LG = 18;
vector<int> arr[N];
int par[N][20],lvl[N];
void dfs(int u, int uu)
{
    par[u][0] = uu;
    lvl[u] = lvl[uu] + 1;
    for (int i = 1; i <= LG; i++)
    {
        par[u][i] = par[ par[u][i - 1] ][i - 1];
    }
    for (auto v: arr[u])
    {
        if (v != uu)
        {
            dfs(v, u);
        }
    }
}
int lca(int u, int v)
{
    if (lvl[u] < lvl[v]) swap(u, v);
    for (int i = LG; i >= 0; i--) 
    {
        if(lvl[par[u][i]] >= lvl[v])u = par[u][i];
    }
    if (u == v) return u;
    for (int i = LG; i >= 0; i--)
        {
            if(par[u][i] != par[v][i])
            {
                u = par[u][i];
                v = par[v][i];
            }
        }
    return par[u][0];
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        int z;cin>>z;
        arr[z].pb(i);
    }
    dfs(1,0);
    while(q--)
    {
        int a,b;cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}
int32_t main()
{
    edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        //cout<<endl;
        solve();
    }
} 
