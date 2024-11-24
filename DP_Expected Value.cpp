//https://atcoder.jp/contests/dp/tasks/dp_i

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
const int N =3005;
double dp[N];
void solve()
{
    int n;cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        double val;cin>>val;
        for(int j=i;j>=0;--j)
        {
            if(j==0)
                dp[j] = dp[j]*(1-val);
            else
                dp[j] = (dp[j-1]*val) + dp[j]*(1-val);
        }
    }
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        int tail = n - i;
        if(i>tail)
        {
            ans+=dp[i];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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

