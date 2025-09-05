//https://codeforces.com/contest/2014/problem/H

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n) 
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" ";
#define vcout(v)        for(auto i:v)cout<<i<<endl;
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
#define ff              first
#define ss              second
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 1e6+9;
int cnt[N];
int arr[N];
const int B = 450;
int have;
bool cmp(pair<pair<int,int>,int>x,pair<pair<int,int>,int>y)
{
    int now = (x.ff.ff)/B , now2 = (y.ff.ff)/B;
    if(now != now2) return (now < now2);
    return ((x.ff.ss) < (y.ff.ss));
}
void add(int pos)
{
    int num = arr[pos];
    cnt[num]++;
    if(cnt[num]%2==0)have--;
    else have++;
}
void rem(int pos)
{
    int num = arr[pos];
    cnt[num]--;
    if(cnt[num]%2==0)have--;
    else have++;
}
void solve()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        cnt[arr[i]]=0;
    }
    have=0;
    int ll=1,rr=1;
    vector<pair<pair<int,int>,int>>v;
    int save[q+1];
    for(int i=0;i<q;i++)
    {
        int a,b;cin>>a>>b;
        v.pb({{a,b},i});
    }
    sort(v.begin(),v.end(),cmp);
    int l=v[0].ff.ff;
    int r=v[0].ff.ss;
    multiset<int>st;
    for(int i=l;i<=r;i++)
    {
        add(i);
    }
    //cout<<have<<endl;
    save[v[0].ss]=have;
    ll=l;rr=r;
    for(int j=1;j<q;j++)
    {
        l=v[j].ff.ff;
        r=v[j].ff.ss;
        for(int i=ll;i<l;i++)
        {
            rem(i);
        }
        for(int i=l;i<ll;i++)
        {
            add(i);
        }
        for(int i=r+1;i<=rr;i++)
        {
            rem(i);
        }
        for(int i=rr+1;i<=r;i++)
        {
            add(i);
        }
        save[v[j].ss]=have;
        ll=v[j].ff.ff;
        rr=v[j].ff.ss;
    }
    for(int i=0;i<q;i++)
    {
        if(save[i])NO;
        else YES;
    }
    for(int i=1;i<=n;i++)cnt[arr[i]]=0;
}
int32_t main()
{
    edm();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
} 
