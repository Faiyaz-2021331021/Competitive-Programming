#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define endl           '\n'
#define pp             pair<int,pair<int,int>>
#define asort(a,n)     sort(a,a+n) 
#define vsort(v)       sort(v.begin(),v.end())
#define vrsort(v)      sort(v.rbegin(),v.rend());
#define YES            cout<<"YES"<<endl
#define NO             cout<<"NO"<<endl
#define yes            cout<<"yes"<<endl
#define no             cout<<"no"<<endl
#define Yes            cout<<"Yes"<<endl
#define No             cout<<"No"<<endl
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int lcs(string &s1,string &s2,int n,int m)
{
    if(n==0 || m==0)return 0;
    if(s1[n-1]==s2[m-1])return 1 + lcs(s1,s2,n-1,m-1);
    else
    {
        return max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
    }
}
void solve()
{
    string s1,s2;cin>>s1>>s2;
    int n = s1.size();int m = s2.size();
    cout<<lcs(s1,s2,n,m)<<endl;
}
signed main()
{
    edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        ///cout<<"Case "<<i<<": ";
        solve();
    }
} 
