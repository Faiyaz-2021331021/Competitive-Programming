////https://www.spoj.com/problems/MPOW/

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
const int N = 100;
const int mod = 1e9 + 7;
int mat[N][N];
int ind[N][N];
void mul(int ind[][N],int arr[][N],int n)
{
    int res[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            res[i][j] = 0;
            for(int k=1;k<=n;k++)
            {
                int val  = (ind[i][k] * arr[k][j]) % mod;
                res[i][j] = (res[i][j] + val) % mod;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ind[i][j] = res[i][j];
        }
    }
}
void calc(int arr[][N],int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==i)ind[i][j]=1;
            else ind[i][j]=0;
        }
    }
    while(m)
    {
        if(m%2)
        {
            mul(ind,arr,n);
            m--;
        }
        else
        {
            mul(arr,arr,n);
            m=m/2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[i][j] = ind[i][j];
            //cout<<arr[i][j]<<" ";
        }
        //cout<<endl;
    }
}
void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>mat[i][j];
    }
    calc(mat,n,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
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
