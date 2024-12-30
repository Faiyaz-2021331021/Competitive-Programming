///https://cses.fi/problemset/task/1111/

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define debug           cout<<"HERE"<<endl;
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 4000000;
int hs1[N],hs2[N];
int inv1[N],inv2[N];
int mod = 1000992299;
int power(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
void hashval1(const string &s,int n) /// hashvalue from left to right ... (s[i]*31^0 + s[i]*31^1 + s[i]*31^2)
{
    int pr = 211;
    int cr = 1;
    inv1[0] = 1;
    hs1[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++)
    {
        char ch = s[i];
        cr = (cr * pr) % mod;
        inv1[i] = power(cr, mod - 2);
        hs1[i] = (hs1[i - 1] + (ch - 'a' + 1) * cr) % mod;
    }
}
void hashval2(const string &s,int n) /// hashvalue from right to left ... (s[i]*31^2 + s[i]*31^1 + s[i]*31^0)
{
    int pr = 211;
    int cr = 1;
    inv2[0] = 1;
    hs2[n-1] = s[n-1] - 'a' + 1;
    for (int i = s.size()-2; i >= 0; i--)
    {
        char ch = s[i];
        cr = (cr * pr) % mod;
        //inv2[n-1-i] = power(cr, mod - 2);
        hs2[i] = (hs2[i + 1] + (ch - 'a' + 1) * cr) % mod;
    }
}
int substr1(int l, int r,int n) ///checking from left to right
{
    int ans = hs1[r];
    if (l > 0)
        ans = (ans - hs1[l - 1] + mod) % mod;
    ans = (ans * inv1[l]) % mod;
    return ans;
}
int substr2(int l, int r,int n) ///checking from right to left
{
    int ans = hs2[l];
    if (r < n-1)ans = (ans - hs2[r + 1] + mod) % mod;
    ans = (ans * inv1[n-1-r]) % mod;
    return ans;
}
vector<int> manacher_odd(string s)
{
        int n = s.size();
        vector<int>d(n);
        int l = 0 , r = -1;
        for(int i = 0 ; i < n ; i ++)
        {
            int now = 1;
            if(i <= r) now = max(1ll,min(r-i+1,d[l+r-i]));
            while(i+now < n && i-now >= 0 && s[i-now] == s[i+now]) now++;
            d[i] = now;
            if(i + d[i] - 1 > r)
            {
                    r = i+d[i]-1;
                    l = i-d[i]+1;
            }
        }
        return d;
}
 
vector<int>manacher_even(string s)
{
        int n = s.size();
        vector<int>d(n);
        int l = 0 , r = -1;
        for(int i = 0 ; i < n ; i ++)
        {
            int now = 0;
            if(i  <= r) now = max(0ll,min(r-i+1,d[l+r-i+1]));
            while(i+now < n && i-now-1 >= 0 && s[i-now-1] == s[i+now]) now++;
            d[i] = now;
            if(i + d[i] - 1 > r)
            {
                r = i + d[i] - 1;
                l = i - d[i];
            } 
        }
        return d;       
}
void solve()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    hashval1(s,n);
    hashval2(s,n);
    if(substr1(0,n-1,n)==substr2(0,n-1,n))
    {
        cout<<s<<endl;return;
    }
    int ans=0;
    vector<int>d1 = manacher_odd(s);
    for(auto i:d1)
    {
        ans = max(((2*i)-1),ans);
    }
    vector<int>d2 = manacher_even(s);
    for(auto i:d2)
    {
        ans = max((2*i),ans);
    }
    int pos=0;
    for(int i=0;i<=n-ans;i++)
    {
        if(substr1(i,i+ans-1,n)==substr2(i,i+ans-1,n))
        {
            //cout<<substr1(i,i+ans-1,n)<<" "<<substr2(i,i+ans-1,n)<<endl;
            pos=i;
            break;
        }
    }
    for(int i=pos;i<pos+ans;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}
