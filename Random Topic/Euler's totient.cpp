////https://www.spoj.com/problems/LCMSUM/

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
const int N = 1000009;
const int mm = 1e6+9;
int phi[N];int str[N];
void phi_1_to_n()
{
    phi[1] = 1;
    for (int i = 0; i <= N; i++)
        phi[i] = i;
    for (int i = 2; i <= N; i++)
    {
        if (phi[i] == i)
        {
            phi[i] /= i;
            phi[i] *= i - 1;
            for(int j=2*i;j<=N;j+=i)
            {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j+=i)
        {
            str[j] += phi[i] * i;
        }
    }
}
void solve()
{
    int n;cin>>n;
    int ans = (str[n] - 1)*n;
    ans = ans / 2;
    ans = ans + n;
    cout<<ans<<endl;
}
int32_t main()
{
    edm();
    phi_1_to_n();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}  
