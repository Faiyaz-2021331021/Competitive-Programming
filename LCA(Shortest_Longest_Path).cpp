#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define endl           '\n'
#define pp             pair<int,pair<int,int>>
#define ppp            pair<pair<int,int>,pair<int,int>>
#define asort(a,n)     sort(a,a+n) 
#define vsort(v)       sort(v.begin(),v.end())
#define vrsort(v)      sort(v.rbegin(),v.rend());
#define YES            cout<<"YES"<<endl
#define NO             cout<<"NO"<<endl
#define yes            cout<<"yes"<<endl
#define no             cout<<"no"<<endl
#define Yes            cout<<"Yes"<<endl
#define No             cout<<"No"<<endl
const int N = 300000;
int parent[N];
const int LG = 18;
vector<pair< int, int > > arr[N];
int par[N][20],lvl[N];int dismx[N][20];int dismn[N][20];
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int findpar(int n)
{
    if(parent[n]==n)return n;
    else return parent[n] = findpar(parent[n]);
}
bool connected(int u,int v)
{
    if(findpar(u)==findpar(v))return true;
    else return false;
}
void match(int u,int v)
{
    u = findpar(u);
    v = findpar(v);
    if(u!=v)parent[v]=u;
}
void dfs(int u, int uu,int uuu)
{
    par[u][0] = uu;
    dismx[u][0] = uuu;
    dismn[u][0] = uuu;
    lvl[u] = lvl[uu] + 1;
    for (int i = 1; i <= LG; i++)
    {
        par[u][i] = par[ par[u][i - 1] ][i - 1];
        dismx[u][i] = max(dismx[u][i - 1], dismx[ par[u][i - 1] ][i - 1]);
        dismn[u][i] = min(dismn[u][i - 1], dismn[ par[u][i - 1] ][i - 1]);
    }
    for (auto v: arr[u])
    {
        if (v.first != uu)
        {
            dfs(v.first, u,v.second);
        }
    }
}
pair<int,int>lca(int u, int v)
{
    if (lvl[u] < lvl[v]) swap(u, v);
    int mx=0;int mn=1e18;
    for (int i = LG; i >= 0; i--) 
    {
        if(lvl[par[u][i]] >= lvl[v])
        {
            mx = max(mx,dismx[u][i]);
            mn = min(mn,dismn[u][i]);
            u = par[u][i];
        }
    }
    if (u == v) return {mx,mn};
    for (int i = LG; i >= 0; i--)
        {
            if(par[u][i] != par[v][i])
            {
                mx = max(mx,dismx[u][i]);
                mx = max(mx,dismx[v][i]);
                mn = min(mn,dismn[u][i]);
                mn = min(mn,dismn[v][i]);
                u = par[u][i];
                v = par[v][i];
            }
        }
    int r1 = max({mx, dismx[u][0], dismx[v][0]});
    int r2 = min({mn, dismn[u][0], dismn[v][0]});
    return {r1,r2};
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        arr[a].pb({b,c});
        arr[b].pb({a,c});
    }
    dfs(1,0,0);
    int q;cin>>q;
    while(q--)
    {
        int a,b;cin>>a>>b;
        cout<<lca(a,b).second<<" "<<lca(a,b).first<<endl;
    }
}
signed main()
{
    edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        ///cout<<"Case "<<i<<": ";
        solve();
    }
}
