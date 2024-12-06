///https://codeforces.com/problemset/problem/433/B

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
void solve()
{
    int n;cin>>n;
    int arr[n+5];int brr[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        brr[i]=arr[i];
    }
    sort(brr+1,brr+1+n);
    int koyta = sqrt(n);
    int block = n/koyta;
    if(n%koyta)block++;
    int sum[block];
    int sum1[block];
    int sm=0;int cnt=0;int pos=0;
    int sm1=0;int pos1=0;
    for(int i=1;i<=n;i++)
    {
        sm+=arr[i];
        sm1+=brr[i];
        cnt++;
        if(cnt==koyta || i==n)
        {
            cnt=0;
            sum[pos++]=sm;
            sum1[pos1++]=sm1;
            sm1=0;
            sm=0;
        }
    }
    int q;cin>>q;
    while(q--)
    {
        int a,l,r;cin>>a>>l>>r;
        if(a==1)
        {
            if(l==r)
            {
                cout<<arr[l]<<endl;
            }
            else
            {
                int start = (l-1)/koyta;
                int end = (r-1)/koyta;
                int ans=0;
                if(start==end)
                {
                    for(int i=l;i<=r;i++)
                    {
                        ans+=arr[i];
                    }
                }
                else
                {
                    for(int i=l;i<=(start+1)*koyta;i++)
                    {
                        ans+=arr[i];
                    }
                    for(int i=start+1;i<end;i++)
                    {
                        ans+=sum[i];
                    }
                    for(int i=end*koyta+1;i<=r;i++)
                    {
                        ans+=arr[i];
                    }
                }
                cout<<ans<<endl;
            }
        }
        else if(a==2)
        {
            if(l==r)
            {
                cout<<brr[l]<<endl;
            }
            else
            {
                int start = (l-1)/koyta;
                int end = (r-1)/koyta;
                int ans=0;
                if(start==end)
                {
                    for(int i=l;i<=r;i++)
                    {
                        ans+=brr[i];
                    }
                }
                else
                {
                    for(int i=l;i<=(start+1)*koyta;i++)
                    {
                        ans+=brr[i];
                    }
                    for(int i=start+1;i<end;i++)
                    {
                        ans+=sum1[i];
                    }
                    for(int i=end*koyta+1;i<=r;i++)
                    {
                        ans+=brr[i];
                    }
                }
                cout<<ans<<endl;
            }
        }
    }
}
int32_t main()
{
    edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
} 
