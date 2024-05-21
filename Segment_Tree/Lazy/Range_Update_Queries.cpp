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
vector<ll>v(N),lazy(4*N);
void build(ll node, ll low, ll high)
{
    if(low==high)
    {
        lazy[node]=v[low];
        return;
    }
    ll mid=(low+high)>>1;
    build(2*node,low,mid);
    build(2*node+1,mid+1,high);
}
void lazyUpdate(ll node, ll low, ll high, ll x, ll y, ll val)
{
    if(y<low || x>high){return;}
    if(x<=low && high<=y){lazy[node]+=val;return;}
    ll mid=(low+high)>>1;
    lazyUpdate(2*node,low,mid,x,y,val);
    lazyUpdate(2*node+1,mid+1,high,x,y,val);
}
ll query(ll node, ll low, ll high, ll x)
{
    if(low>x || high<x){return 0;}
    if(high==low){return lazy[node];}
    if(lazy[node])
    {
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        lazy[node]=0;
    }
    ll mid=(low+high)>>1;
    return query(2*node, low, mid, x)+query(2*node+1,mid+1,high,x);
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        for(i=1;i<=n;i++){cin>>v[i];}
        build(1,1,n);
        while(q--)
        {
            ll x,y,z;
            cin>>x;
            x--;
            if(x)
            {
                cin>>x;
                cout<<query(1,1,n,x)<<endl;
            }
            else
            {
                cin>>x>>y>>z;
                lazyUpdate(1,1,n,x,y,z);
            }
        }

    }
}
/***
https://cses.fi/problemset/task/1651

This is the solution using lazy propagation.

But this problem can also be solved by using difference array. 
For example, using a bit:
1) Add 'u' to a index.
2) Add '-u' to b+1 index.
3) When queried, print the sum upto xth index.

***/

