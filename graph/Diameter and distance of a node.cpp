#include<bits/stdc++.h>
using namespace std;
#define ll            long long
#define pb             push_back
#define endl           '\n'
#define debug          cout<<"here"<<endl
#define ff             first
#define ss             second
#define pr             pair<int,int>
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 3e5+5;
vector<int> g[N];
void dfs_dist(int u, int p, int d, vector<int>& dist)
{
    dist[u] = d;
    for (int v : g[u])
    {
        if (v != p)
        {
            dfs_dist(v, u, d + 1, dist);
        }
    }
}
vector<int> getMaxDistances(int n)
{
    vector<int> tempDist(n + 1, 0);
    dfs_dist(1, 0, 0, tempDist);
    int D1 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (tempDist[i] > tempDist[D1]) D1 = i;
    }
    vector<int> distD1(n + 1, 0);
    dfs_dist(D1, 0, 0, distD1);
    int D2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (distD1[i] > distD1[D2]) D2 = i;
    }
    vector<int> distD2(n + 1, 0);
    dfs_dist(D2, 0, 0, distD2);
    vector<int> maxDist(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        maxDist[i] = max(distD1[i], distD2[i]);
    }
    return maxDist; 
}
vector<int> getMinDistancesToDiameterEndpoints(int n)
{
    vector<int> tempDist(n + 1, 0);
    dfs_dist(1, 0, 0, tempDist);
    int D1 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (tempDist[i] > tempDist[D1]) D1 = i;
    }
    vector<int> distD1(n + 1, 0);
    dfs_dist(D1, 0, 0, distD1);
    int D2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (distD1[i] > distD1[D2]) D2 = i;
    }
    vector<int> distD2(n + 1, 0);
    dfs_dist(D2, 0, 0, distD2);
    vector<int> minDist(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        minDist[i] = min(distD1[i], distD2[i]);
    }
    return minDist; 
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> maxDist = getMaxDistances(n);
    vector<int> v;
    for(int i = 1; i <= n; i++)
    {
        v.pb(maxDist[i]);
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++)
    {
        auto it = lower_bound(v.begin(), v.end(), i);
        int koto = it - v.begin();
        koto = min(koto + 1, n);
        cout << koto << " ";
    }
    cout << endl;
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
/*
 */
