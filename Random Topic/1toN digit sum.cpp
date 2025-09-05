///https://codeforces.com/contest/2132/problem/D

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define ff              first
#define ss              second
#define debug           cout<<"HERE"<<endl;
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("outputtt.txt","w",stdout);
    #endif
}
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
int Nto1(int n)
{
    if (n <= 0) return 0;
    int res = 0;
    int factor = 1;
    while (factor <= n)
    {
        int higher = n / (factor * 10);
        int current = (n / factor) % 10;
        int lower = n % factor;
        res += higher * 45 * factor;
        res += (current * (current - 1) / 2) * factor;
        res += current * (lower + 1);
        factor *= 10;
    }

    return res;
}
void solve()
{
    int n;cin>>n;
    int cur=0;int got=0;
    string ss = "";
    int xtra=0;
    for(int i=1;i<17;i++)
    {
        int prev = cur;
        cur = cur + (9*i) * pwr(10,i-1);
        if(cur>=n)
        {
            int koyta = n - prev;
            int poss = koyta / i;

            got = got + poss;
            // cout<<got<<endl;
            string nw = to_string(got+1);
            int rem = koyta%i;
            for(int j=0;j<rem;j++)
            {
                // cout<<nw[j]<<endl;
                xtra = xtra + (nw[j] - '0');
            }
            break;
        }
        ss += "9";
        got = stoll(ss);
    }
    // cout<<idk(got)<<endl;
    cout<<Nto1(got) + xtra<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case "<<i<<": ";
        solve();
    }
}
