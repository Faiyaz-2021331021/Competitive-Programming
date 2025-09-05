//// https://codeforces.com/contest/2001/problem/C


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
int vis[1005][1005];
vector<pair<int,int>>v;
int ask(int i, int j)
{
    cout << "? " << i << ' ' << j << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}
void check(int l, int r)
{
    if(vis[l][r]) return;
    vis[l][r] = 1;
    int x = ask(l, r);
    if(x == l || x == r)
    {
        //cout<<l<<" "<<r<<" ";
        v.push_back({l, r});
        return;
    }
    else check(x, r);
}
 
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)vis[i][j]=0;
    }
    v.clear();
    for(int i=2;i<=n;i++)
    {
        check(1,i);
    }
    cout << "! ";
    for(auto it: v)cout<<it.first<<" "<<it.second<<" ";cout<<endl;cout.flush();
    return;
}
int32_t main()
{
    edm();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": "<<endl;
        solve();
    }
} 
