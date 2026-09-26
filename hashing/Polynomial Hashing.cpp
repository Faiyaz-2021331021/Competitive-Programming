//// https://codeforces.com/contest/126/problem/B


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
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 1e6;
const int mod = 1e9+7;
const int fix = 31;
int hs[N]; /// 0 indexing
int inv[N];
int power(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)ans = (ans * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
void Hashval(string s) {
    int pr = 31;
    int cr = 1;
    inv[0] = 1;
    hs[0] = s[0] - 'a' + 1;
    int hash = hs[0];
    for (int i = 1; i < s.size(); i++)
    {
        char ch = s[i];
        cr = (cr * pr) % mod;
        inv[i] = power(cr, mod - 2);
        hs[i] = (hs[i - 1] + (ch - 'a' + 1) * cr) % mod;
    }
}

int substr(int l, int r)
{
    int ans = hs[r];
    if (l > 0)ans -= hs[l - 1];
    if (ans < 0)ans += mod;

    ans = (ans * inv[l]) % mod;
    
    if (ans < 0)ans += mod;
        
    return ans;
}
void solve()
{
    string s;cin>>s;
    int n = s.size()-1;
    Hashval(s);
    int l=0;int h = n;
    vector<pair<int,int>>mt;
    for(int i=0;i<=n;i++)
    {
        //cout<<substr(0,i)<<" ";
        //cout<<substr(14-i,14)<<endl;
        if(substr(0,i)==substr(n-i,n))
        {
            mt.pb({i+1,substr(0,i)});
        }
    }
    vrsort(mt);
    /*for(auto i:mt)
    {
        cout<<i.first<<endl;
    }*/
    string str = "Just a legend";
    int ans=-1;
    for(auto i:mt)
    {
        int z = i.first;
        int zz = i.second;
        for(int i=1;i<=n-z;i++)
        {
            int vl = substr(i,i+z-1);
            if(vl==zz)
            {
                ans=z;break;
            }
        }
        if(ans!=-1)break;
    }
    if(ans==-1)cout<<"Just a legend"<<endl;
    else for(int i=0;i<ans;i++)cout<<s[i];
}
int32_t main()
{
    edm();
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": "<<endl;
        solve();
    }
} 
