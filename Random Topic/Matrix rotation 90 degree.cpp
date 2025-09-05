#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n)
#define arsort(a,n)     sort(a, a + n, greater<T>());
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
void solve()
{
    int n;cin>>n;
    int mat[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>mat[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)swap(mat[i][j], mat[j][i]); 
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n/2;j++)
        {
           swap(mat[i][j],mat[i][n-j+1]); /// clockwise
	         swap(mat[i][j], mat[n-i+1][j]); /// Anticlockwise
        }
    }
    
}
int32_t main()
{ 
    edm();
    int t = 1;
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        //cout<<"Case "<<i<<": "<<endl;
        solve();
    }
}
