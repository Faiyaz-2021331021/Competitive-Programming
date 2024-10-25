////https://atcoder.jp/contests/abc356/tasks/abc356_e?lang=en

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
const int N = 4e6+9;
int cnt[N];
int koto[N];
int nsum(int n)
{
    if(n<=0)return 0;
    return (n*(n+1))/2;
}
void solve()
{
    int n;cin>>n;
    int mx=0;set<int>st;
    map<int,int>mp;int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        koto[x]++;
        mx = max(mx,x);
        st.insert(x);
        mp[x]++;
        sum+=x;
    }
    for(int i=1;i<N;i++)
    {
        cnt[i] = cnt[i-1] + koto[i];
    }
    int ans=0;
    for(auto i:st)
    {
        if(i==1)continue;
        int qq = mp[i];
        ans = ans + nsum(qq-1);
        for(int j=i+i;j<=mx+i;j+=i)
        {
            int kt = cnt[j-1]-cnt[j-i-1];
            int cc = (j-i-1/i);
            if(j-i-1==i-1)
            {
                kt = kt - mp[i];
            }
            ans = ans + mp[i]*((cc*kt)/i);
        }
    }
    ans = ans + mp[1]* (sum - mp[1]);
    ans = ans + nsum(mp[1] - 1);
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
