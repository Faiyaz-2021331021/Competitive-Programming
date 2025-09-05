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
int mx(int arr[],int n,int val) ///return immediate borota
{
    int low = 0;
    if(val>arr[n-1])return -1;
    int high = n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]>=val)
        {
            high = mid-1;
            ans = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}
int mn(int arr[],int n,int val) ///suto ta
{
    int low = 0;
    if(val<arr[0])return -1;
    int high = n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]>val)
        {
            high = mid-1;
        }
        else
        {
            ans = mid;
            low = mid+1;
        }
    }
    return ans;
}
void solve()
{
    int n,m,d;cin>>n>>m>>d;
    int arr[n],brr[m];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int j=0;j<m;j++)cin>>brr[j];
    //
    asort(arr,n);
    asort(brr,m);
    //cout<<mx(arr,n,10)<<endl;
    //for(int i=0;i<n;i++)cout<<brr[i]<<endl;
    int diff[m][2];
        int ans=-1;
        for(int i=0;i<m;i++)
        {
            int d1 = brr[i]+d;
            int d2 = max(0ll,brr[i]-d);
            //cout<<d1<<" "<<d2<<endl;
            diff[i][0] = d2;
            diff[i][1] = d1;
        }
        for(int i=0;i<m;i++)
        {
            //cout<<diff[i][0]<<" "<<diff[i][1]<<endl;
            int upre = mx(arr,n,diff[i][0]);
            int nise = mn(arr,n,diff[i][1]);
            //cout<<upre<<" "<<nise<<endl;
            if(upre<=nise && nise!=-1 && upre!=-1)
            {
                ans = max(ans,arr[nise] + brr[i]);
            }
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
        //cout<<"Case "<<i<<": ";
        solve();
    }
} 
