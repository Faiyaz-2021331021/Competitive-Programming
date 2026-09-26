/// https://codeforces.com/contest/271/problem/D

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
#define ff              first
#define ss              second
#define mp              make_pair
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 1e6;
const int mod1 = 998244353; 
const int mod2 = 1000992299; 
const int pr1 = 31; 
const int pr2 = 37;
 
int hs1[N], hs2[N];
int inv1[N], inv2[N];
 
int power(int a, int n, int mod)
{
    int ans = 1;
    while (n) {
        if (n & 1) ans = ((ans) * a) % mod;
        n >>= 1;
        a = ((a) * a) % mod;
    }
    return ans;
}
 
void Hashval(string s)
{
    int cr1 = 1, cr2 = 1;
    inv1[0] = inv2[0] = 1;
    hs1[0] = s[0] - 'a' + 1;
    hs2[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++)
    {
        char ch = s[i];
        cr1 = ((cr1) * pr1) % mod1;
        cr2 = ((cr2) * pr2) % mod2;
        inv1[i] = power(cr1, mod1 - 2, mod1);
        inv2[i] = power(cr2, mod2 - 2, mod2);
        hs1[i] = (hs1[i - 1] + ((ch - 'a' + 1) * cr1) % mod1) % mod1;
        hs2[i] = (hs2[i - 1] + ((ch - 'a' + 1) * cr2) % mod2) % mod2;
    }
}
 
pair<int, int> substr(int l, int r)
{
    int hash1 = hs1[r];
    if (l > 0) hash1 = (hash1 - hs1[l - 1] + mod1) % mod1;
    hash1 = ((hash1) * inv1[l]) % mod1;
    int hash2 = hs2[r];
    if (l > 0) hash2 = (hash2 - hs2[l - 1] + mod2) % mod2;
    hash2 = ((hash2) * inv2[l]) % mod2;
    return {hash1, hash2};
}
void solve()
{   
    string s;cin>>s;
    int arr[26];string str = "";
    string idk;cin>>idk;
    for(int i=0;i<26;i++)
    {
        int val = idk[i] - '0';
        arr[i]=val^1;
    }
    Hashval(s);
    int k;cin>>k;
    vector<pair<int,int>>ss;
    for(int i=0;i<s.size();i++)
    {
        str = "";
        int got=0;
        for(int j=i;j<s.size();j++)
        {
            str+=s[j];
            int pos = s[j] - 'a';
            got+=arr[pos];
            if(got<=k)
            {
                pair<int,int> val = substr(i,j);
                ss.pb(val);
            }
            else break;
        }
    }
    vsort(ss);
    int ans=1;
    if(ss.size()!=0)
    {
        for(int i=0;i<ss.size()-1;i++)
        {
            //cout<<ss[i]<<" "<<ss[i+1]<<endl;
            if(ss[i]!=ss[i+1])ans++;
        }
    }
    else ans=0;
    cout<<ans<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}
