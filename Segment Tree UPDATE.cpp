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
    tree[node] = tree[left] + tree[right];
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)return; 
    if (b >= i && e <= i) 
    {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2 + 1;
    int Right = node * 2 + 2;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++)cin>>arr[i];
    build(0,0,n-1);
    update(0,0,n-1,u,0);
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
