////https://codeforces.com/problemset/problem/2008/F

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
    /*
    Here in this problem we have to find a1*aj for all pairs then divide it by total number of pairs;
    if n=5, we get 1-5,1-4,1-3,1-2,2-5..... total of nsum of(n-1);
    So first we find demonitors P and numerator Q;
    As we have to find (P/Q) % mod it means (P * Q^-1) %mod;
    so we need Q^-1;
    By Fermet Theorem A^(m-1) % m = 1 if gcd(A,m)=1;
    divide by A^-1 both side we get
    A^(m-2) % m = A^-1;
    So we need to find (A ^ m - 2) what is done in 55th line
    */
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans=0;int sum=0;
    for(int i=0;i<n;i++)
    {
        ans = (ans + ((sum*arr[i]) % mod ))%mod;
        sum= (sum + arr[i]) % mod;
    }
    int koyta = ((n*(n-1))/2)%mod;
    int koto = pwr(koyta,mod-2);
    cout<<(ans * koto)%mod<<endl;
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
