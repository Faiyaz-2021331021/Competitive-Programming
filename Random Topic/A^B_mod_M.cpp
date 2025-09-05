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
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int mod = 1e9 + 7;
//no mod
int pwr(int a,int b) ///no mod
{
    int ans=1;
    while(b>0)
    {
        if(b%2!=0)ans=(ans*a);
        a = (a*a);
        b>>=1;
    }
    return ans;
}

//with mod
int pwr(int a,int b)
{
    int ans=1;
    while(b>0)
    {
        if(b%2!=0)ans=(ans*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}
void solve()
{
    int a,b;cin>>a>>b;
    cout<<pwr(a,b)<<endl;
}
signed main()
{
    edm();
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ///cout<<i<<"=";cout<<endl;
        ///cout<<"Case "<<i<<": ";
        solve();
    }
} 
