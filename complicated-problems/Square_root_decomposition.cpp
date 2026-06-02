#include<bits/stdc++.h>
using namespace std;
#define ll             long long
#define pb              push_back
#define endl            '\n'
#define debug           cout<<"HERE"<<endl;
#define ff              first
#define ss              second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int B = 500;
const int N = 300005;
int arr[N];
vector<vector<int>>blocks;
void build(int n)
{
    int nm = (n + B - 1)/B;
    blocks.assign(nm,vector<int>());
    for(int i=0;i<n;i++)
    {
        blocks[i/B].pb(arr[i]);
    }
    for(int i=0;i<nm;i++)
    {
        sort(blocks[i].begin(),blocks[i].end());
    }
}
int query(int l,int r,int val)
{
    int ans=0;
    int st = l/B;
    int nd = r/B;
    if(st==nd)
    {
        for(int i=l;i<=r;i++)
        {
            if(arr[i]<val)ans++;
        }
        return ans;
    }
    int stlf = (st+1)*B - 1;
    for(int i=l;i<=stlf;i++)
    {
        if(arr[i]<val)ans++;
    }
    for(int i=st+1;i<nd;i++)
    {
        auto it = lower_bound(blocks[i].begin(),blocks[i].end(),val);
        ans = ans + distance(blocks[i].begin(),it);
    }
    int ndrt = nd*B;
    for(int i=ndrt;i<=r;i++)
    {
        if(arr[i]<val)ans++;
    }
    return ans;
}
void update_block(int blk,int age,int pore)
{
    auto it = lower_bound(blocks[blk].begin(),blocks[blk].end(),age);
    blocks[blk].erase(it);

    auto it1 = lower_bound(blocks[blk].begin(),blocks[blk].end(),pore);
    blocks[blk].insert(it1,pore);
}
void update(int l,int r)
{
    if(l==r || arr[l]==arr[r])return;

    int bl = l/B;
    int br = r/B;
    update_block(bl,arr[l],arr[r]);
    update_block(br,arr[r],arr[l]);
    swap(arr[l],arr[r]);
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++)cin>>arr[i];
    build(n);
    while(q--)
    {
        int a;cin>>a;
        if(a==1)
        {
            int l,r,m;cin>>l>>r>>m;
            cout<<query(l-1,r-1,m)<<endl;
        }
        else
        {
            int l,r;cin>>l>>r;
            update(l-1,r-1);
        }
    }
}
int32_t main()
{
    edm();
    int t = 1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}
