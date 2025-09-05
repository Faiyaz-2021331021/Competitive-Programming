///https://www.spoj.com/problems/MARYBMW/
/// Reach Nth node from 1 with highest distance

#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define el             '\n'
#define pp             pair<int,pair<int,int>>
#define asort(a,n)     sort(a,a+n) 
#define vsort(v)       sort(v.begin(),v.end())
#define vrsort(v)      sort(v.rbegin(),v.rend());
const int N = 999999;
int vis[N];
vector<vector<pair<int, int>>> arr(N);
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
    priority_queue<pp>pq;
    vector<int>v;
    int flag=0;
    for(int i=0;i<m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        arr[a].pb({b,c});
        arr[b].pb({a,c});
    }
    for(auto i:arr[1])
    {
        pq.push({i.second,{1,i.first}});
    }
    while(!pq.empty())
    {
        auto cnode = pq.top();
        pq.pop();
        vis[cnode.second.first]=1;
        int pnode = cnode.second.second;
        v.pb(cnode.first);
        if(pnode==n){flag=1;break;}
        if(vis[pnode]==0)
        {
            vis[pnode]=1;
            {
                for(auto j:arr[pnode])
                {
                    if(vis[j.first]==0)
                    {
                        pq.push({j.second,{pnode,j.first}});
                    }
                }
            }
        }
    }
    vsort(v);
    if(flag)cout<<v[0]<<endl;
    else cout<<-1<<endl;
    for(int i=0;i<=n;i++)
        {
            vis[i]=0;
            arr[i].clear();
        }
}
signed main()
{
    edm();
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ///cout<<"Case "<<i<<": ";
        solve();
    }
} 
