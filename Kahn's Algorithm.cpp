///https://vjudge.net/problem/SPOJ-TOPOSORT


#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define el             '\n'
#define pp             pair<int,pair<int,int>>
#define asort(a,n)     sort(a,a+n) 
#define vsort(v)       sort(v.begin(),v.end())
#define vrsort(v)      sort(v.rbegin(),v.rend());
#define prrr           pair<int,int>
#define YES            cout<<"YES"<<endl
#define NO             cout<<"NO"<<endl
#define yes            cout<<"yes"<<endl
#define no             cout<<"no"<<endl
#define Yes            cout<<"Yes"<<endl
#define No             cout<<"No"<<endl
#define revpq(pq)      priority_queue<int,vector<int>,greater<int>>pq; 
const int N = 999999;
int vis[N];
int par[N];
vector<int>arr[N];
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<int>ind(n+5,0);
    while(m--)
    {
        int a,b;cin>>a>>b;
        arr[a].pb(b);
        ind[b]++;
    }
    revpq(pq);
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)pq.push(i);
    }
    vector<int>v;
    while(!pq.empty())
    {
        int tp = pq.top();
        pq.pop();
        v.pb(tp);
        for(auto i:arr[tp])
        {
            ind[i]--;
            if(ind[i]==0)pq.push(i);
        }
    }
    if(v.size()!=n){cout<<"Sandro fails."<<endl;return;}
    for(auto i:v)cout<<i<<" ";
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
