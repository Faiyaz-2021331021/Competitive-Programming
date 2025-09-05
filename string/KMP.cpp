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
vector<int> build_lps(string p)
{
    int sz = p.size();
    vector<int> lps;
    lps.assign(sz + 1, 0);
    int j = 0;
    lps[0] = 0;
    for(int i = 1; i < sz; i++)
    {
        while(j >= 0 && p[i] != p[j])
        {
            if(j >= 1) j = lps[j - 1];
            else j = -1;
        }
        j++;
        lps[i] = j;
    }
    return lps;
}
vector<int>getpos(vector<int>lps, string s, string p)
{
    vector<int>ans;
    int psz = p.size(), sz = s.size();
    int j = 0;
    for(int i = 0; i < sz; i++)
    {
        while(j >= 0 && p[j] != s[i])
        {
            if(j >= 1) j = lps[j - 1];
            else j = -1;
        }
    j++;
    if(j == psz)
    {
        j = lps[j - 1];
        /// j = 0; to avoid overlapping
        ans.push_back(i - psz + 1);
    }
  }
  return ans;
}
void solve()
{
    string str;
    cin>>str;
    string s;
    cin>>s;
    vector<int>lps = build_lps(str);
    vector<int>ans1 = getpos(lps,str,s);
    if(!ans1.size()){cout<<"Not Found"<<endl;}
    else
    {
        cout<<ans1.size()<<endl;
        for(auto i:ans1)cout<<i+1<<" ";
        cout<<endl;
    }
}
int32_t main()
{
    edm();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        if(t)cout<<endl;
    }
} 
