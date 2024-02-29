///Dijastra
///https://vjudge.net/problem/AtCoder-abc340_d

#include<bits/stdc++.h>
using namespace std;
#define int long long
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
void solve()
{
    int n;cin>>n;
    vector<vector<pair<int, int>>> arr(n + 5);
    for(int i=1;i<=n-1;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        arr[i].push_back({i+1,a});
        arr[i].push_back({c,b});
    }
    vector<int>dist(500005,1e18);
    pair<int,int>p;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty())
    {
        pair<int,int>cur = pq.top();
        pq.pop();
        int u = cur.second;
        if(cur.first > dist[u])continue;
        for(auto i:arr[u])
        {
            int v = i.first;
            int w = i.second;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    cout<<dist[n]<<endl;
}
signed main()
{
    edm();
    int t;t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        ///cout<<"Case "<<i<<": ";
        solve();
    }
} 
