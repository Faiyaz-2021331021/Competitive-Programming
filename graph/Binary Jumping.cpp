///https://cses.fi/problemset/task/1750/

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n) 
#define arrout(a,n)     for(int i=1;i<=n;i++)cout<<a[i]<<" ";
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
const int N = 2e5+5;
const int lvl = 25;
int par[N][lvl];
int jump(int a, int d)
{
    for (int i = 0; i < lvl; i++)
        if (d & (1 << i))a = par[a][i];
    return a;
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>par[i][0];
    for(int i=1;i<lvl;i++)
    {
        for(int j=1;j<=n;j++)
        {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    while (q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<jump(a,b)<<endl;
    }
}
int32_t main()
{ 
    edm();
    int t = 1;
    //cin >> t;
    for(int i=1; i<=t; i++)
    {
        //cout<<"Case "<<i<<": "<<endl;
        solve();
    }
}
