///https://codeforces.com/contest/1096/problem/D

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
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
string s,t;
const int N = 1e5+5;
int arr[N];
int dp[N][5];
int magic(int i,int j)
{
    if(j==4)return 1e18;
    if(i<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]=='d' && j==0)
    {
        int take = magic(i-1,j+1);
        int nottake = magic(i-1,j) + arr[i];
        dp[i][j] = min(take,nottake);
        return dp[i][j];
    }
    else if(s[i]=='r' && j==1)
    {
        int take = magic(i-1,j+1);
        int nottake = magic(i-1,j) + arr[i];
        dp[i][j] = min(take,nottake);
        return dp[i][j];
    }
    else if(s[i]=='a' && j==2)
    {
        int take = magic(i-1,j+1);
        int nottake = magic(i-1,j) + arr[i];
        dp[i][j] = min(take,nottake);
        return dp[i][j];
    }
    else if(s[i]=='h' && j==3)
    {
        int take = 1e18;
        int nottake = magic(i-1,j) + arr[i];
        dp[i][j] = min(take,nottake);
        return dp[i][j];
    }
    else
    {
        dp[i][j] = magic(i-1,j);
        return dp[i][j];
    }
}
void solve()
{   
    int n;cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        dp[i][0]=-1;
        dp[i][1]=-1;
        dp[i][2]=-1;
        dp[i][3]=-1;
        dp[i][4]=-1;
    }
    cout<<magic(n-1,0);
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
