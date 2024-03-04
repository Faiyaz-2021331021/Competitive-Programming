#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define el             '\n'
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
int arr[300000];
int tree[900000];
void build(int node, int s, int e)
{
    if (s == e)
    {
        tree[node] = arr[s];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (s + e) / 2;
    build(left, s, mid);
    build(right, mid + 1, e);
    //tree[node] = tree[left] + tree[right];
    tree[node] = min(tree[left],tree[right]);
    //tree[node] = max(tree[left],tree[right]);
}
int sumquery(int node, int s, int e, int l, int r)
{
    if (l > e || r < s)return 0; 
        
    if (s >= l && e <= r)return tree[node];
        
    int left = node * 2 + 1; 
    int right = node * 2 + 2;
    int mid = (s + e) / 2;
    int p1 = sumquery(left, s, mid, l, r);
    int p2 = sumquery(right, mid + 1, e, l, r);
    return p1 + p2;
}
int minquery(int node,int s,int e,int l,int r)
{
    if(r<l)return 1e18;
    if(l==s && r==e)return tree[node];
    int mid = (s+e)/2;
    return min(minquery(node*2+1,s,mid,l,min(r,mid)),minquery(node*2+2,mid+1,e,max(l,mid+1),r));
}
int maxquery(int node,int s,int e,int l,int r)
{
    if(r<l)return -1;
    if(l==s && r==e)return tree[node];
    int mid = (s+e)/2;
    return max(maxquery(node*2+1,s,mid,l,min(r,mid)),maxquery(node*2+2,mid+1,e,max(l,mid+1),r));
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++)cin>>arr[i];
    build(0,0,n-1);
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<minquery(0,0,n-1,l-1,r-1)<<endl;
    }
}
int32_t main()
{
    edm();
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<": "<<endl;
        solve();
    }
} 
