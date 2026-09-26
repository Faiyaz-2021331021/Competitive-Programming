///https://codeforces.com/contest/894/problem/E

#include<bits/stdc++.h>
using namespace std;
#define ll            long long
#define pb             push_back
#define endl           '\n'
#define debug          cout<<"here"<<endl
#define ff             first
#define ss             second
#define pr             pair<int,int>
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
}
struct Edge {
    int u, v, w;
};
const int N = 3e6+5;
int tarjan_index = 0;
stack<int> st;
vector<vector<int>> sccs;
vector<int>nodes;
vector<Edge>edges;
vector<Edge>new_edges;
vector<pair<int,int>>g[N];
vector<int>vis(N);
vector<ll>dp(N, -1);
vector<vector<pair<int, int>>> graph(N);
vector<int> indices(N, -1), lowlink(N, -1);
vector<bool> on_stack(N, false);
vector<ll> scc_internal_weights(N, 0);
vector<int> node_to_scc(N, 0);
ll calc(ll n)
{
    ll low = 1;
    ll high = n;
    ll where = 0;
    while(low<=high)
    {
        ll mid = (low+high)/2;
        ll koto = (mid*(mid+1))/2;
        if(koto<=n)
        {
            where = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    ll val = n * (where + 1);
    ll bad = (where*(where+1)*(where + 2))/6;
    return val - bad;
}
void strongconnect(int v)
{
    indices[v] = tarjan_index;
    lowlink[v] = tarjan_index;
    tarjan_index++;
    st.push(v);
    on_stack[v] = true;

    for (const auto& edge : graph[v])
    {
        int w = edge.first;
        if (indices[w] == -1)
        {
            strongconnect(w);
            lowlink[v] = min(lowlink[v], lowlink[w]);
        }
        else if (on_stack[w])
        {
            lowlink[v] = min(lowlink[v], indices[w]);
        }
    }

    if (lowlink[v] == indices[v])
    {
        vector<int> scc;
        while (true)
        {
            int w = st.top();
            st.pop();
            on_stack[w] = false;
            scc.push_back(w);
            if (w == v) break;
        }
        sccs.push_back(scc);
    }
}
void compressCycles()
{
    for (const auto& edge : edges)
    {
        graph[edge.u].push_back({edge.v, edge.w});
    }
    for (int node : nodes)
    {
        if (indices[node] == -1)
        {
            strongconnect(node);
        }
    }
    int max_node = 0;
    for (int node : nodes)
    {
        max_node = max(max_node, node);
    }
    int next_super_node_id = max_node + 1;

    for (const auto& scc : sccs)
    {
        if (scc.size() == 1)
        {
            node_to_scc[scc[0]] = scc[0];
        }
        else
        {
            for (int node : scc)
            {
                node_to_scc[node] = next_super_node_id;
            }
            next_super_node_id++;
        }
    }
    
    for (const auto& edge : edges)
    {
        if (node_to_scc[edge.u] == node_to_scc[edge.v])
        {
            scc_internal_weights[node_to_scc[edge.u]] += calc(edge.w);
            // cout<<edge.u<<" "<<edge.v<<" "<<edge.w<<endl;
        }
    }
    for (const auto& edge : edges)
    {
        int scc_u = node_to_scc[edge.u];
        int scc_v = node_to_scc[edge.v];

        if (scc_u != scc_v)
        {
            // int new_weight = edge.w + scc_internal_weights[scc_v];
            int new_weight = edge.w;
            new_edges.pb({scc_u, scc_v, new_weight});
        }
    }
}
ll dfs(ll n)
{
    if(dp[n]!=-1)return dp[n];
    ll mx = 0;
    for(auto i:g[n])
    {
        mx = max(mx , i.ss + dfs(i.ff));
    }
    return dp[n] = scc_internal_weights[n] + mx;
}
void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        nodes.push_back(i);
    }
    while(m--)
    {
        int a,b,c;cin>>a>>b>>c;
        edges.pb({a,b,c});
    }
    int s;cin>>s;
    compressCycles();
    // for(auto i:scc_internal_weights)
    // {
    //     cout<<i.ff<<" "<<i.ss<<endl;
    // }
    for(auto i:new_edges)
    {
        g[i.u].pb({i.v,i.w});
        // cout<<i.u<<" "<<i.v<<" "<<i.w<<endl;
    }
    ll ans=dfs(node_to_scc[s]);
    cout<<ans<<endl;
}
int32_t main()
{
    edm();
    int t = 1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        // cout<<"Case "<<i<<":";
        // cout<<endl;
        solve();
        // if(i!=t)cout<<endl;
    }
}
/*
 */
