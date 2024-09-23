//// https://codeforces.com/contest/797/problem/C
//// Minimal String - Codeforces(797C)

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n) 
#define arsort(a,n)      sort(a,a+n,greater<int>()) 
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
void solve()
{
    string s;cin>>s;
    int prev=0;string str="";
    int arr[s.size()];
    for(int i=0;i<s.size();i++)arr[i]=0;
    for(int i=0;i<26;i++)
    {
        char z = 'a' + i;
        int last=prev;
        int flag=0;
        for(int i=prev-1;i>=0;i--)
        {
            if(arr[i]==0 && s[i]<=z)
            {
                arr[i]=1;
                str+=s[i];
            }
            else if(arr[i]==0 && s[i]>z)
            {
                break;
            }
        }
        for(int i=prev;i<s.size();i++)
        {
            if(s[i]==z)
            {
                arr[i]=1;
                str+=z;
                last=i;
                flag=1;
            }
        }
        for(int i=prev-1;i>=0;i--)
        {
            if(s[i]==z && flag==1 && arr[i]==0)
            {
                arr[i]=1;
                str+=z;
            }
            else break;
        }
        
        prev = last;
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        if(arr[i]==0)str+=s[i];
    }
    cout<<str<<endl;
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
