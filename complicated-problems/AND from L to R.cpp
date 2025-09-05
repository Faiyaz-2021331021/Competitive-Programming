///https://codeforces.com/contest/1878/problem/E


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
const int N = 3e5;
int pref[N][32];
int arr[N];
int pwr(int a,int b)
{
    int ans=1;
    while(b>0)
    {
        if(b%2!=0)ans=(ans*a);
        a = (a*a);
        b>>=1;
    }
    return ans;
}
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<30;j++)pref[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        int q = arr[i];
        int cnt=29;
        while(q)
        {
            pref[i][cnt--] = q%2;
            q = q/2;
        }
        for(int j=cnt;j>=0;j--)pref[i][j]=0;
    }
    for(int i=0;i<30;i++)
    {
        for(int j=1;j<=n;j++)
        {
            pref[j][i] = pref[j][i] + pref[j-1][i];
        }
    }
    int q;cin>>q;
    while(q--)
    {
        int l, k;
        cin >> l >> k;
        if(arr[l]<k)
        {
            cout<<-1<<" ";
            continue;
        }
        int low=0;int high=n-l;
        int ans=0;int num=0;
        while(low<=high)
        {
            int s = (low+high)/2;
            int cur[30];
            for(int j=29;j>=0;j--)
            {
                //cout<<pref[s+l][j] - pref[l-1][j]<<endl;
                if(pref[s+l][j] - pref[l-1][j]==s+1)
                {
                    cur[j] = 1;
                }
                else cur[j] =0;
            }
            int gt = 0;
            for(int j=29;j>=0;j--)
            {
                num+=(pwr(2,gt++) * cur[j]);
            }
            gt=0;
            if(num>=k)
            {
                low=s+1;
                ans=max(ans, s);
            }
            else high=s-1;
            num=0;
        }
        cout<<ans+l<<" ";
    }
    cout<<endl;
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
