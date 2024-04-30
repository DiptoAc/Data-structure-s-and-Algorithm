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
ll n,m;
vector<ll>v(N),tr(4*N);
void build(ll node, ll x, ll y)
{
    if(x==y)
    {
        tr[node]=v[x];
        return;
    }
    ll mid=(x+y)/2;
    build(2*node,x,mid);
    build(2*node+1,mid+1,y);
    if((n&1))
    {
        ll k=log2(node);
        if((k&1))
        {
            tr[node]=tr[2*node]^tr[2*node+1];
        }
        else
        {
            tr[node]=tr[2*node]|tr[2*node+1];
        }
    }
    else
    {
        ll k=log2(node);
        if((k&1))
        {
            tr[node]=tr[2*node]|tr[2*node+1];
        }
        else
        {
            tr[node]=tr[2*node]^tr[2*node+1];
        }
    }
    return;
}

ll query(ll node, ll x, ll y, ll ind, ll val)
{
    if(x>ind || y<ind){return tr[node];}
    if(x==y)
    {
        return tr[node]=val;
    }
    ll mid = (x+y)/2;
    ll k= log2(node);
    if((n&1))
    {
        if((k&1))
        {
            return tr[node]=query(2*node,x,mid,ind,val)^query(2*node+1,mid+1,y,ind,val);
        }
        else
        {
            return tr[node]=query(2*node,x,mid,ind,val)|query(2*node+1,mid+1,y,ind,val);
        }
    }
    else
    {
        if((k&1))
        {
            return tr[node]=query(2*node,x,mid,ind,val)|query(2*node+1,mid+1,y,ind,val);
        }
        else
        {
            return tr[node]=query(2*node,x,mid,ind,val)^query(2*node+1,mid+1,y,ind,val);
        }
    }
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        m=powl(2,n);
        for(i=1;i<=m;i++){cin>>v[i];}
        build(1,1,m);
        while(q--)
        {
            ll x,y;
            cin>>x>>y;
            cout<<query(1,1,m,x,y)<<endl;
        }
    }
}
/***
Problem name : Xenia and Bit Operations
Problem type : Basic segment tree (Build & Query) - No Update.
//https://codeforces.com/contest/339/problem/D
***/
