////https://codeforces.com/problemset/problem/1200/E


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
vector<int> z_function(string &s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++)
    {
        if(i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if(i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    for(int i=1;i<n;i++)
    {
        string str;cin>>str;
        int mx=0;
        string ss = "";
        if(str.size()>s.size())
        {
            ss = str + s;
        }
        else
        {
            ss+=str;
            for(int j=s.size()-str.size();j<s.size();j++)
            {
                ss+=s[j];
            }
        }
        vector<int>v = z_function(ss);
        for(int j=str.size();j<v.size();j++)
        {
            if(v[j]==v.size()-j)
            {
                mx = v[j];
                break;
            }
        }
        for(int j=mx;j<str.size();j++)s+=str[j];
    }
    cout<<s<<endl;
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
