///https://cses.fi/problemset/task/1673/

#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define endl           '\n'
#define debug          cout<<"here"<<endl
#define ff             first
#define ss             second
#define pr             pair<int,int>
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //#endif
}
struct edge
{
    int a,b,c;
};
void solve()
{
    int n,m;cin>>n>>m;
    vector<edge>edges;
    for(int i=0;i<m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        edges.pb({a,b,-c});
    }
    vector<int>dist(n+5,1e18);
    dist[1] = 0;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u = edges[j].a;
            int v = edges[j].b;
            int w = edges[j].c;
            if(dist[u] != 1e18 && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u = edges[j].a;
            int v = edges[j].b;
            int w = edges[j].c;
            if(dist[u] != 1e18 && dist[u] + w < dist[v])
            {
                dist[v] = -1e18;
            }
        }
    }
    if(dist[n] == -1e18)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<-dist[n]<<endl;
    }
}
int32_t main()
{
    edm();
    int t = 1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case "<<i<<":";
        // cout<<endl;
        solve();
        // if(i!=t)cout<<endl;
    }
}

