///https://vjudge.net/contest/717347#problem/F


#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define debug           cout<<"HERE"<<endl;
#define ff              first
#define ss              second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int mod = 1000992299;
void solve()
{
    int n,q;cin>>n>>q;
    int arr[n+1];
    int brr[n+1];
    int val[n+5];
    for(int i=0;i<=n+2;i++)
    {
        val[i] = rng();
    }
    arr[0] = 0;
    brr[0] = 0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        arr[i] = val[x];
        arr[i] = (arr[i] + arr[i-1]);
    }
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        brr[i] = val[x];
        brr[i] = (brr[i] + brr[i-1]);
    }
    while(q--)
    {
        int a,b,c,d;cin>>a>>b>>c>>d;
        int v1 = (arr[b] - arr[a-1]);
        int v2 = (brr[d] - brr[c-1]);
        if(v1==v2)
        {
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}

int32_t main()
{
    edm();
    int t = 1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
} 
