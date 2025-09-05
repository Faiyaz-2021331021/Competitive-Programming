///https://atcoder.jp/contests/dp/tasks/dp_c
///Memoization and tabulation


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
int dp[200000][3];
int arr[200000][3];
void vac(int n) /////Tabulation Process
{
    for(int i=0;i<3;i++)
    {
        dp[0][i] = arr[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
            {
                int v1 = dp[i-1][1] + arr[i][0];
                int v2 = dp[i-1][2] + arr[i][0];
                if(v1>v2)
                {
                    dp[i][0] = v1;
                }
                else
                {
                    dp[i][0] = v2;
                }
            }
            else if(j==1)
            {
                int v1 = dp[i-1][0] + arr[i][1];
                int v2 = dp[i-1][2] + arr[i][1];
                if(v1>v2)
                {
                    dp[i][1] = v1;
                }
                else
                {
                    dp[i][1] = v2;
                }
            }
            else if(j==2)
            {
                int v1 = dp[i-1][0] + arr[i][2];
                int v2 = dp[i-1][1] + arr[i][2];
                if(v1>v2)
                {
                    dp[i][2] = v1;
                }
                else
                {
                    dp[i][2] = v2;
                }
            }
        }
    }
}
void solve()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)cin>>arr[i][j];
    }
    vac(n);
    int mx=0;
    for(int i=0;i<3;i++)
    {
        mx = max(mx,dp[n-1][i]);
    }
    cout<<mx<<endl;
}
int vac(int n,int last) ///Memoization
{
    if(n==1)
    {
        int mx=0;
        for(int i=1;i<=3;i++)
        {
            if(i!=last)
            {
                mx = max(mx,arr[1][i]);
            }
        }
        return mx;
    }
    if(dp[n][last]!=-1)return dp[n][last];
    int mx = 0;
    for(int i=1;i<=3;i++)
    {
        if(i!=last)
        {
            int point = arr[n][i] + vac(n-1,i);
            mx = max(point,mx);
        }
    }
    return dp[n][last] = mx;
}
void solve()
{
    int n;cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<vac(n,-1);
}
int32_t main()
{
    edm();
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": "<<endl;
        solve();
    }
} 
