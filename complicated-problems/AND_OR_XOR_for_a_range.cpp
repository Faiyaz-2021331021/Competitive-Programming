#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define endl           '\n'
#define debug          cout<<"here"<<endl
#define ff             first
#define ss             second
#define vsort(v)       sort(v.begin(),v.end())
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int pwr(int a,int b)
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
int func(int n,int p)
{
    int koybar = n / p;
    int rem = n % p;
    koybar = koybar * (p/2);
    // cout<<rem<<" "<<p/2<<endl;
    if(rem>=p/2)
    {
        koybar = koybar + (rem - (p/2));
    } 
    return koybar;
}
void solve()
{
    int l,r;cin>>l>>r;
    int how = r - l + 1;
    vector<int>bit(64,0);
    for(int i=0;i<63;i++)
    {
        // cout<<func(r+1,pwr(2,i+1))<<" ";
        // cout<<func(l,pwr(2,i+1))<<endl;

        bit[i] = func(r+1,pwr(2,i+1)) - func(l,pwr(2,i+1));
    }
    int a=0,rr=0,x=0;
    for(int i=0;i<62;i++)
    {
        if(bit[i]==how)
        {
            a = a | (1ll<<i);
        }
        if(bit[i])
        {
            rr = rr | (1ll<<i);
        }
        if(bit[i]%2!=0)
        {
            x = x | (1ll<<i);
        }
    }
    cout<<a<<" ";
    cout<<rr<<" ";
    cout<<x<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}
