///https://codeforces.com/problemset/problem/1548/B


#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define endl           '\n'
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
const int N = 2e5+9;
int table[N][25];
int arr[N];
void build(int n)
{
	for(int i=1; i<n; i++)
	{
		table[i][0] = arr[i];
	}
	for(int i=1; i<25; i++)
	{
		for(int j=0; j+(1<<i)-1<n; j++)
		{
			table[j][i] = __gcd(table[j][i-1],table[j+(1<<(i-1))][i-1]);
		}
	}
}
int Query(int l,int r)
{
	int q = log2(r-l+1);
	return __gcd(table[l][q],table[r-(1<<q)+1][q]);
}
void solve()
{
    int n;cin>>n;
    int brr[n];
    for(int i=0;i<n;i++)cin>>brr[i];
    for(int i=1;i<n;i++)
    {
    	arr[i] = abs(brr[i]-brr[i-1]);
    }
    if(n==1)
    {
    	cout<<n<<endl;
    	return;
    }
    build(n);
    int ans=0;
    for(int i=1;i<n;i++)
    {
    	int low=i,high=n-1;
    	int can=0;
    	while(low<=high)
    	{
    		int mid = (low+high)/2;
    		if(Query(i,mid)>1)
    		{
    			can=mid;
    			low=mid+1;
    		}
    		else high=mid-1;
    	}
    	ans = max(ans,(can-i+1));
    	//cout<<i<<" "<<can<<endl;
    }
    cout<<ans+1<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case "<<i<<": ";
        solve();
    }
} 
