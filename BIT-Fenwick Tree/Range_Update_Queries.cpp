#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =2e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<ll>v,updates;
struct BIT
{
    ll sz;
    vector<ll>bit;
    BIT(ll sz)
    {
        this->sz=sz;
        bit.resize(sz);
    }
    BIT(vector<ll>v):BIT(v.size())
    {
        for(int i=1;i<sz;i++)
        {
            add(v[i],i);
        }
    }
    void add(ll val, ll idx)
    {
        while(idx<sz)
        {
            bit[idx]+=val;
            idx+=idx&-idx;
        }
    }
    ll sum(ll idx)
    {
        ll ans=0;
        while(idx>0)
        {
            ans+=bit[idx];
            idx-=idx&-idx;
        }
        return ans;
    }
    ll sum(ll x,ll y)
    {
        return sum(y)-sum(x-1);
    }
};
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        v.resize(n+1);
        updates.resize(n+1);
        BIT bit(updates);
        for(i=1;i<=n;i++){cin>>v[i];}
        while(q--)
        {
            ll x,y,z;
            cin>>x;x--;
            if(x)
            {
                cin>>x;
                cout<<v[x]+bit.sum(x)<<endl;
            }
            else
            {
                cin>>x>>y>>z;
                bit.add(z,x);
                bit.add(-z,y+1);
            }
        }
    }
}
/***
https://cses.fi/problemset/task/1651


This problem can also be solved by using difference array.
For example, using a bit:
1) Add 'u' to a index.
2) Add '-u' to b+1 index.
3) When queried, print the sum upto xth index.

***/

