///https://serious-oj.com/problems/674dc32fe761330008d346ed

#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define debug           cout<<"HERE"<<endl;
#define ff              first
#define ss              second
#define VPT vector <PT>
#define eps 1e-9
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

struct PT
{
    double x, y;
    PT() {x=0, y=0;}
    PT (int _x, int _y) : x(_x), y(_y) {}

    PT operator- (const PT &a) const
    {
        return PT(x-a.x, y-a.y);
    }
};
int sign(double x)
{
    return (x > eps) - (x < -eps);
}
double cross (PT a, PT b)
{
    return a.x * b.y - a.y * b.x;
}
int orientation (PT a, PT b, PT c)
{
    return sign(cross(b-a, c-a));
}
bool is_point_on_seg (PT a, PT b, PT p)
{
    if (abs(cross(p - b, a-b)) < eps)
    {
        if (p.x<min(a.x,b.x) || p.x > max(a.x,b.x))return 0;
        if (p.y<min(a.y,b.y) || p.y > max(a.y,b.y))return 0;
        return 1;
    }
    return 0;
}
bool is_point_on_polygon(VPT &p,const PT& z) ///-1 in 0 wall 1 outside
{
    int n = p.size();
    for(int i = 0; i < n; i++)
    if(is_point_on_seg(p[i], p[(i+1)%n], z))return 1;
    return 0;
}
int winding_number(VPT &p, const PT& z)
{
    if(is_point_on_polygon(p, z)) return 1e9; int n = p.size(),ans = 0 ;
    for(int i = 0; i < n; ++i)
    {
        int j=(i+1)%n;
        bool below = p[i].y < z.y;
        if(below != (p[j].y < z .y))
        {
            auto orient = orientation(z, p[j], p[i]);
            if(orient == 0) return 0; if(below == (orient > 0)) ans += below ? 1 : -1;
        }
    }
    return ans;
}
int is_point_in_polygon(VPT &p, const PT& z)
{
    int k = winding_number(p, z); return k == 1e9 ? 0 :k == 0 ? 1 : -1;
} 
void solve ()
{
    int n; cin >>n;
    vector <PT> inp(n);
    for (auto &it : inp)
    {
        int x,y; cin >>x >>y;
        it= PT(x, y);
    }
    int x, y; cin >>x >>y;
    PT p = PT(x, y);
    int num = is_point_in_polygon(inp, p);
    if (num ==-1)cout <<"YES\n";
    else cout <<"NO\n";
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

