//https://codeforces.com/problemset/problem/459/D
//Pramida and Pasmaks problem.
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
const ll N =1e6+1;
ll n,m;
vector<ll>vec(N,0),tr(4*N);
void build(ll node, ll x, ll y)
{
    if(x==y){tr[node]=vec[x];return;}
    ll mid= (x+y)/2;
    build(2*node,x,mid);
    build(2*node+1,mid+1,y);
    tr[node]=tr[2*node]+tr[2*node+1];
    return;
}

void update(ll node ,ll x, ll y, ll ind)
{
    if(ind<x || y<ind){return;}
    if(x==y)
    {
        vec[x]--;
        tr[node]=vec[x];return;
    }
    ll mid = (x+y)/2;
    update(2*node,x,mid,ind);
    update(2*node+1,mid+1,y,ind);
    tr[node]=tr[2*node]+tr[2*node+1];
}

ll query(ll node,ll x,ll y,ll up)
{
    if(x>up){return 0;}
    if(y<=up){return tr[node];}
    ll mid= (x+y)/2;
    return query(2*node,x,mid,up)+query(2*node+1,mid+1,y,up);
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n;
        vector<ll>v(n+1);
        for(i=1;i<=n;i++){cin>>v[i];}
        vector<ll>cnt_f(n+1),cnt_b(n+1);
        map<ll,ll>mp;
        for(i=n;i>=1;i--)
        {
            ll t=v[i];
            cnt_b[i]=++mp[t];
            vec[cnt_b[i]]++;
        }
        mp.clear();
        ll ans=0;
        build(1,1,n);
        for(i=1;i<=n;i++)
        {
            cnt_f[i]=++mp[v[i]];
            update(1,1,n,cnt_b[i]);
            ans+=query(1,1,n,cnt_f[i]-1);
            //cout<<query(1,1,n,cnt_f[i]-1)<<endl;
        }
        cout<<ans<<endl;
    }
}


