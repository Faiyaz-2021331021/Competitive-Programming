////https://codeforces.com/contest/1999/problem/F


#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n) 
#define arrout(a,n)     for(int i=1;i<=n;i++)cout<<a[i]<<" ";
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
const int N = 1e9 + 7;
const int sz = 300000;
int comb[sz];
int arr[sz];
void makefact()
{
    comb[0] = 1;
    for(int i = 1; i <= 250000; i++)
    {
        comb[i] = (comb[i-1] * i) % N;
    }
}

int modInverse(int a, int mod)
{
    int res = 1, exp = mod - 2;
    while(exp > 0)
    {
        if(exp % 2 == 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        exp /= 2;
    }
    return res;
}

int nCr(int n, int r)
{
    if(r > n) return 0;
    int d1 = comb[n];
    int n1 = comb[n-r];
    int n2 = comb[r];
    int n3 = (n1 * n2) % N;
    return (d1 * modInverse(n3, N)) % N;
}
void solve()
{
    int n,k;cin>>n>>k;
    arr[0]=1;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr, arr + n+1, greater<int>());
    //arrout(arr,n); 
    int mid = (k/2) + 1;
    int ans=0;
    for(int i=mid;i<=n-mid+1;i++)
    {
        if(arr[i]==1)
        {
            int z = ((nCr(i-1,k/2)*nCr(n-i,k/2)));
            ans = ((ans + z)%N);
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    edm();
    makefact();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": "<<endl;
        solve();
    }
} 
