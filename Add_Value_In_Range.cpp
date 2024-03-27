///https://cses.fi/problemset/task/1651/


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
int lazytree[900000];
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
void updaterange(int node, int s, int e, int l, int r,int val)
{
    if(lazytree[node] != 0)
    {
        tree[node] += (e - s + 1) * lazytree[node];
        if(s != e)
        {
            lazytree[node * 2 + 1] += lazytree[node];
            lazytree[node * 2 + 2] += lazytree[node];
        }
        lazytree[node] = 0;
    }
    if(s > e || s > r || e < l)
        return;
    if(s >= l && e <= r)
    {
        tree[node] += (e - s + 1) * val;
        if(s != e)
        {
            lazytree[node * 2 + 1] += val;
            lazytree[node * 2 + 2] += val;
        }
        return;
    }
    int m = (s + e) / 2;
    updaterange(node * 2 + 1, s, m, l, r, val);
    updaterange(node * 2 + 2, m + 1, e, l, r, val);
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}
int getquery(int node, int s, int e, int pos)
{
    if(lazytree[node] != 0)
    {
        tree[node] += lazytree[node] * (e - s + 1);
        if(s != e)
        {
            lazytree[node * 2 + 1] += lazytree[node];
            lazytree[node * 2 + 2] += lazytree[node];
        }
        lazytree[node] = 0;
    }
    if(s == e)
        return tree[node];
    int m = (s + e) / 2;
    if(pos <= m)
        return getquery(2 * node + 1, s, m, pos);
    else
        return getquery(2 * node + 2, m + 1, e, pos);
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++)cin>>arr[i];
    build(0,0,n-1);
    while(q--)
    {
        int aa;cin>>aa;
        if(aa==1)
        {
            int bb,cc,dd;cin>>bb>>cc>>dd;
            updaterange(0,0,n-1,bb-1,cc-1,dd);
        }
        else if(aa==2)
        {
            int bb;cin>>bb;
            int ans = getquery(0,0,n-1,bb-1);
            cout<<ans<<endl;
        }
    }
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
