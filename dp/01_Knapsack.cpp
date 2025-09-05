///https://atcoder.jp/contests/abc060/tasks/arc073_b

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
const int N = 1000;
int wt[N];int val[N];
int dp[N][N];
map<pair<int,int>,int>mp;
int knapsack(int n,int w) ///// IF weight/capacity has large value
{
    if(w<=0)return 0;
    if(n<=0)return 0;
    auto it = mp.find({n,w});
    if(it!=mp.end())return mp[{n,w}];
    if(wt[n-1]>w)
    {
        mp[{n,w}] = knapsack(n-1,w);
    }
    else
    {
        mp[{n,w}] = max((knapsack(n-1,w)),(knapsack(n-1,w-wt[n-1]) + val[n-1]));
    }
    return mp[{n,w}];
}

int knapsack(int n,int w)
{
    if(w<=0)return 0;
    if(n<=0)return 0;
    if(dp[n][w]!=-1)return dp[n][w];
    if(wt[n-1]>w)
    {
        dp[n][w] = knapsack(n-1,w);
    }
    else
    {
        dp[n][w] = max(knapsack(n-1,w),knapsack(n-1,w-wt[n-1]) + val[n-1]);
    }
    return dp[n][w];
}
void solve()
{
    int n;cin>>n;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)dp[i][j]=-1;
    }
    for(int i=0;i<n;i++)cin>>wt[i];
    for(int i=0;i<n;i++)cin>>val[i];
    int wt;cin>>wt;
    cout<<knapsack(n,wt)<<endl;

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
