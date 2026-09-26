///https://codeforces.com/contest/2010/problem/C2

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n) 
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" ";
#define vcout(v)        for(auto i:v)cout<<i<<endl;
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
const int mod = 10000000000000061; 
const int fix = 233;
int hs[N]; /// 0 indexing
int inv[N]; 
int power(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1) ans = (__int128(ans) * a) % mod;
        n >>= 1;
        a = (__int128(a) * a) % mod;
    }
    return ans;
}

void Hashval(string s)
{
    int pr = 31;
    int cr = 1;
    inv[0] = 1;
    hs[0] = s[0] - 'a' + 1;
    
    for (int i = 1; i < s.size(); i++)
    {
        char ch = s[i];
        cr = (__int128(cr) * pr) % mod; 
        inv[i] = power(cr, mod - 2); 
        hs[i] = (hs[i - 1] + (__int128(ch - 'a' + 1) * cr) % mod) % mod;
    }
}

int substr(int l, int r)
{
    int ans = hs[r];
    if (l > 0) ans -= hs[l - 1];
    if (ans < 0) ans += mod;

    ans = (__int128(ans) * inv[l]) % mod;
    if (ans < 0) ans += mod;

    return ans;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size() - 1;
    Hashval(s);

    int l = 0;
    int h = n;
    multimap<int, int> mp;

    for (int i = 0; i < n; i++) 
    {
        int val = substr(0, i);
        mp.insert({val, i});
    }

    int ans = -1;

    for (int i = 1; i < n; i++)
    {
        int val = substr(i, n);
        auto it = mp.find(val);

        if (it != mp.end()) 
        {
            if (it->second >= i) 
            {
                ans = i;
                break;
            }
        }
    }

    if (ans != -1) 
    {
        cout << "YES" << endl;
        for (int i = ans; i <= n; i++) cout << s[i];
        cout << endl;
    } 
    else 
    {
        cout << "NO" << endl;
    }
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
