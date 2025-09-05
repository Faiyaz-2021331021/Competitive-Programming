///https://cses.fi/problemset/task/2428/

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
#define ff              first
#define ss              second
#define mp              make_pair
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
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans=0;
    int left=0;int cnt=0;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]] == 0)cnt++;
        mp[arr[i]]++;
        while(cnt>k)
        {
            mp[arr[left]]--;
            if (mp[arr[left]] == 0)cnt--;
            left++;
        }
        ans+=i-left+1;
    }
    cout<<ans<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}
