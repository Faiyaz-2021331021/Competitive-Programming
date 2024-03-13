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
const int N = 100;
int a[N];
int dp[N][N];
int mcm(int i,int j)
{
    if(i==j)return 0;
    if(dp[i][j]!=-1){return dp[i][j];}
    dp[i][j]=1e9;
    for(int k=i;k<j;k++)
    {
        dp[i][j] = min(dp[i][j], mcm(i,k)+mcm(k+1,j) + a[i-1]*a[k]*a[j]);
    }
    return dp[i][j];
}
void solve()
{
    int n;cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<mcm(1,n-1)<<endl;
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
