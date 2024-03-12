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
#define INF            1e18
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int arr[300000];
pair<int,int> tree[900000];
pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)return a;
    if (b.first > a.first)return b;
    return make_pair(a.first, a.second + b.second);
}
void build(int node, int s, int e)
{
    if (s == e)
    {
        tree[node] = make_pair(arr[s], 1);
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (s + e) / 2;
    build(left, s, mid);
    build(right, mid + 1, e);
    tree[node] = combine(tree[left],tree[right]);
    //tree[node] = min(tree[left],tree[right]);
    //tree[node] = max(tree[left],tree[right]);
}
pair<int,int> get_max(int v, int s, int e, int l, int r)
{
    if (l > r)return make_pair(-INF, 0);
        
    if (l == s && r == e)return tree[v];
        
    int m = (s + e) / 2;
    return combine(get_max(v*2+1, s, m, l, min(r, m)), get_max(v*2+2, m+1, e, max(l, m+1), r));
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++)cin>>arr[i];
    build(0,0,n-1);
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<get_max(0,0,n-1,l,r).first<<" "<<get_max(0,0,n-1,l,r).second<<endl;
    }
}
int32_t main()
{
    edm();
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": "<<endl;
        solve();
    }
} 
