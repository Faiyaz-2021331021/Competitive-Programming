/// https://atcoder.jp/contests/abc051/tasks/abc051_d?lang=en


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
const int INF = 1e18;
int dist[105][105];
void solve()
{
    int n,m;cin>>n>>m;
    vector<pp>v;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)dist[i][j]=0;
            else dist[i][j] =INF;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = c;
        v.pb({c,{a,b}});
    }
    int i, j, k;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int cnt=0;
    for(auto i:v)
    {
        if(dist[i.ss.ff][i.ss.ss]!=i.ff)cnt++;
    }
    cout<<cnt<<endl;
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
