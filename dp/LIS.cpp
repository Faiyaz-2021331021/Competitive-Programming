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
void find_lis(vector<int> a)
{
    //int lis = 0;
    vector<int>lis(a.size(),1);
    vector<int>par(a.size(),-1);
    for(int i=1;i<a.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j] < a[i] && lis[i] < lis[j]+1)
            {
                lis[i] = lis[j]+1;
                par[i] = j;
            }
        }
    }
    int mx=0;int ind=0;
    for(int i=0;i<a.size();i++)
    {
        if(lis[i] > mx)
        {
            mx = lis[i];
            ind = i;
        }
    }
    vector<int>seq;
    while(ind>=0)
    {
        seq.pb(a[ind]);
        ind = par[ind];
    }
    for(int i=seq.size()-1;i>=0;i--)cout<<seq[i]<<" ";
}
void solve()
{
    int n;cin>>n;
    vector<int>v;
    while(n--)
    {
        int a;cin>>a;
        v.pb(a);
    }
    find_lis(v);
}
int32_t main()
{
    edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<i<<" ";
        solve();
    }
} 
