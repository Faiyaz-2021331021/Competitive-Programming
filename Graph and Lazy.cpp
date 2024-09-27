////https://atcoder.jp/contests/abc138/tasks/abc138_d

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n) 
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
#define ff              first 
#define ss              second
#define debug           cout<<"HERE"<<endl;
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 2e5 + 5;
vector<int>g[N];
int par[N];
int child[N];
int vis[N];
void dfs(vector<int>&v,int n)
{
    vis[n] = 1;
    v.pb(n);
    for(auto i:g[n])
    {
        if(vis[i]==0)
        {
            par[i] = n;
            dfs(v,i);
        }
    }
}
int arr[300000];
int tree[900000];
int lazytree[900000];
void build(int node, int s, int e)
{
    if (s == e)
    {
        tree[node] = arr[s];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (s + e) / 2;
    build(left, s, mid);
    build(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}
void updaterange(int node, int s, int e, int l, int r,int val)
{
    if(lazytree[node] != 0)
    {
        tree[node] += (e - s + 1) * lazytree[node];
        if(s != e)
        {
            lazytree[node * 2 + 1] += lazytree[node];
            lazytree[node * 2 + 2] += lazytree[node];
        }
        lazytree[node] = 0;
    }
    if(s > e || s > r || e < l)
        return;
    if(s >= l && e <= r)
    {
        tree[node] += (e - s + 1) * val;
        if(s != e)
        {
            lazytree[node * 2 + 1] += val;
            lazytree[node * 2 + 2] += val;
        }
        return;
    }
    int m = (s + e) / 2;
    updaterange(node * 2 + 1, s, m, l, r, val);
    updaterange(node * 2 + 2, m + 1, e, l, r, val);
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}
int getquery(int node, int s, int e, int pos)
{
    if(lazytree[node] != 0)
    {
        tree[node] += lazytree[node] * (e - s + 1);
        if(s != e)
        {
            lazytree[node * 2 + 1] += lazytree[node];
            lazytree[node * 2 + 2] += lazytree[node];
        }
        lazytree[node] = 0;
    }
    if(s == e)
        return tree[node];
    int m = (s + e) / 2;
    if(pos <= m)
        return getquery(2 * node + 1, s, m, pos);
    else
        return getquery(2 * node + 2, m + 1, e, pos);
}
void solve()
{
    int n,q;cin>>n>>q;
    build(0,0,n-1);
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int>v;
    par[1] = 0;
    dfs(v,1);
    int pos[n+1];
    //vcout(v);cout<<endl;
    for(int i=0;i<v.size();i++)
    {
        pos[v[i]] = i;
    }
    for(int i=v.size()-1;i>0;i--)
    {
        int p = par[v[i]];
        int wh = pos[p];
        child[wh] += 1 + child[i];
    }
    //for(int i=0;i<n;i++)cout<<child[i]<<endl;
    while(q--)
    {
        int a,b;cin>>a>>b;;
        int wh = pos[a];
        //cout<<wh<<" ";
        int koyta = wh + child[wh];
        //cout<<koyta<<endl;
        updaterange(0,0,n-1,wh,koyta,b);
    }

    for(int i=0;i<n;i++)
    {
        // cout<<v[i]<<" ";
        // cout<<getquery(0,0,n-1,i)<<" ";
        par[v[i]] = getquery(0,0,n-1,i);
    }
    for(int i=1;i<=n;i++)cout<<par[i]<<" ";
}
int32_t main()
{
    edm();
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}
