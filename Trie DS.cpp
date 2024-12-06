///https://codeforces.com/problemset/problem/706/D


#include<bits/stdc++.h>
using namespace std;
#define int             long long
#define pb              push_back
#define endl            '\n'
#define pp              pair<int,pair<int,int>>
#define asort(a,n)      sort(a,a+n) 
#define arrout(a,n)     for(int i=1;i<=n;i++)cout<<a[i]<<" ";
#define vcout(v)        for(auto i:v)cout<<i<<" ";
#define vsort(v)        sort(v.begin(),v.end())
#define vrsort(v)       sort(v.rbegin(),v.rend());
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
struct Node
{
    Node *links[2];
    int value = -1;
    bool containthis(int n)
    {
        return (links[n]!=NULL);
    }
    void put(int num,Node* node)
    {
        links[num] = node;
    }
    Node* get(int num)
    {
        return links[num];
    }
    void setEnd(int val)
    {
        value = val;
    }
    void clearEnd()
    {
        value = -1; 
    }
    int getEndValue()
    {
        return value;
    }
    bool isEmpty()
    {
        return links[0] == NULL && links[1] == NULL;
    }
};
class Trie
{
    bool removeHelper(Node* node, int num, int bitIndex)
    {
        if (bitIndex < 0)
        {

            if (node->getEndValue() == -1) return false;
            node->clearEnd();
            return node->isEmpty();
        }

        int bit = (num >> bitIndex) & 1;
        if (!node->containthis(bit)) return false;

        bool shouldDeleteChild = removeHelper(node->get(bit), num, bitIndex - 1);

        if (shouldDeleteChild)
        {
            delete node->links[bit];
            node->links[bit] = NULL;
        }

        return node->isEmpty() && node->getEndValue() == -1;
    }
    private: Node* root;
    public:

        Trie()
        {
            root = new Node();
        }

        void insert(int num)
        {
            Node* node = root;
            for (int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) & 1;
                if(!node->containthis(bit))
                {
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
            node->setEnd(num);
        }

        vector<int>search(int num)
        {
            vector<int>v;
            Node* node = root;
            for (int i = 31; i >= 0; i--)
            {
                int bit = (num >> i) & 1; 
                int toggledBit = bit ^ 1;
                if (node->containthis(toggledBit))
                {
                    v.pb(toggledBit);
                    node = node->get(toggledBit);
                }
                else
                {
                    v.pb(bit);
                    node = node->get(bit);
                }
            }
            return v;
        }
        void remove(int num)
        {
            removeHelper(root, num, 31);
        }

};
void solve()
{   
    Trie trie;
    int n;
    cin>>n;
    trie.insert(0);
    map<int,int>mp;
    mp[0]++;
    for(int i=0;i<n;i++)
    {
        char a;int b;
        cin>>a>>b;
        if(a=='+')
        {
            mp[b]++;
            if(mp[b]==1)trie.insert(b);   
        }
        else if(a=='-')
        {
            mp[b]--;
            if(mp[b]==0)trie.remove(b);
        }
        else if(a=='?')
        {
            vector<int> v = trie.search(b);
            for(int i=31;i>=0;i--)
            {
                int rem = b%2;
                b = b/2;
                v[i] = v[i]^rem;
            }
            int ans=0;int nw=0;
            for(int i=31;i>=0;i--)
            {
                ans = ans + (v[i]*pow(2,nw++));
            }
            cout<<ans<<endl;
        }
    }
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
