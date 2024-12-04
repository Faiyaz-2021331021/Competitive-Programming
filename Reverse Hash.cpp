////https://codeforces.com/contest/1326/problem/D2

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n)
#define arsort(a,n)     sort(a,a+n,greater<int>())
#define arrout(a,n)     for(int i=1;i<=n;i++)cout<<a[i]<<" ";
#define vcout(v)        for(auto i:v)cout<<i<<endl;
#define vsort(v)        sort(v.begin(),v.end())
#define vrsort(v)       sort(v.rbegin(),v.rend());
#define pqr             priority_queue<int,vector<int>,greater<int>>
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
const int N = 1e6+5;
const __int128 mod = 1000000000039;
const int fix = 31;
int hs[N];
int hsi[N];
int inv[N];
int power(__int128 a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)ans = (ans * a) % mod;
        n >>= 1;
        a = (__int128(a) * a) % mod;
    }
    return ans;
}
void Hashval(const string& s, const string& s2)
{
    int n = s.size();
    int pr = 31;
    int cr = 1;
    inv[0] = 1;
    hs[0] = s[0] - 'a' + 1;
    hsi[0] = s[n - 1] - 'a' + 1;
    for (int i = 1; i < s.size(); i++) {
        char ch = s[i];
        char ch1 = s2[i];
        cr = (__int128(cr) * pr) % mod;
        inv[i] = power(__int128(cr), mod - 2);
        hs[i] = (hs[i - 1] + (__int128(ch - 'a' + 1) * cr) % mod) % mod;
        hsi[i] = (hsi[i - 1] + (__int128(ch1 - 'a' + 1) * cr) % mod) % mod;
    }
}
int substr1(int l, int r)
{
    int ans = hs[r];
    if (l > 0)ans -= hs[l - 1];
    if (ans < 0)ans += mod;

    ans = (__int128(ans) * inv[l]) % mod;

    if (ans < 0)ans += mod;

    return ans%mod;
}
int substr2(int l, int r)
{
    int ans = hsi[r];
    if (l > 0)ans -= hsi[l - 1];
    if (ans < 0)ans += mod;

    ans = (__int128(ans) * inv[l]) % mod;

    if (ans < 0)ans += mod;

    return ans%mod;
}
void solve()
{
    string s;cin>>s;
    if(s.size()==1)
    {
        cout<<s<<endl;
        return;
    }
    if(s.size()==2)
    {
        if(s[0]==s[1])cout<<s<<endl;
        else cout<<s[0]<<endl;
        return;
    }
    int n = s.size()-1;int ind=-1;
    string ans="",ans1="";
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[n])
        {
            ans1+=s[i];
            ans+=s[i];
            n--;
            ind=i;
        }
        else break;
    }
    string ss1 ="";
    for(int i=ind+1;i<=n;i++)
    {
        ss1+=s[i];
    }
    if(ans.size()==s.size()/2)
    {
        cout<<s<<endl;
        return;
    }
    string ss2 = ss1;
    reverse(ss2.begin(),ss2.end());
    Hashval(ss1,ss2);
    n = ss1.size();
    int cur=0;
    for(int i=0;i<n;i++)
    {
        int rem = ss1.size()-1-i;
        int v1 = substr1(0,i);
        int v2 = substr2(rem,ss2.size()-1);
        if(v1==v2)
        {
            cur=i;
        }
    }
    string temp = ans;
    reverse(temp.begin(),temp.end());
    for(int i=0;i<=cur;i++)ans+=ss1[i];
    ans+=temp;
    //cout<<ans<<endl;
    for(int i=0;i<n;i++)
    {
        int rem = ss1.size()-1-i;
        int v1 = substr2(0,i);
        int v2 = substr1(rem,ss2.size()-1);
        if(v1==v2)
        {
            cur=i;
        }
    }
    temp = ans1;
    reverse(temp.begin(),temp.end());
    for(int i=ss1.size()-cur-1;i<=ss1.size()-1;i++)ans1+=ss1[i];
    ans1+=temp;
    if(ans1.size()>ans.size())
    {
        cout<<ans1<<endl;
    }
    else cout<<ans<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}
