///https://atcoder.jp/contests/abc153/tasks/abc153_e?lang=en

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
#define debug           cout<<"HERE"<<endl;
void edm()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 2e4;
int dp[N];
int kom(int arr[],int brr[],int n,int hp)
{
    if(hp<=0)return 0;
    if(dp[hp]!=-1)return dp[hp];
    int ans=1e18;
    for(int i=0;i<n;i++)
    {
        if(hp-arr[i]>=0)
        {
            ans = min(ans,kom(arr,brr,n,hp-arr[i])+brr[i]);
        }
        else
        {
            ans = min(ans,brr[i]);
        }
    }
    return dp[hp] = ans;
}
void solve()
{
    int n,h;cin>>h>>n;
    int arr[n];
    int brr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cin>>brr[i];
    }
    for(int i=1;i<=h+5;i++)dp[i]=-1;;
    dp[0]=0;
    cout<<kom(arr,brr,n,h)<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    //cin >> t;
    for(int i=1; i<=t; i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
}
