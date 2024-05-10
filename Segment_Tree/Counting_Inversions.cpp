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
const ll INF =1e16;
const ll M =1e9+7;
const ll N =1e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
struct Node
{
    vector<ll>v;
    ll inv,sz;
    Node()
    {
        v.resize(41);
        inv=0;
        sz=0;
    }
};
Node tr[4*N],emp;
vector<ll>ar(N);
Node mrg(Node L, Node R)
{
    Node temp;
    temp.sz=L.sz+R.sz;
    ll cntL=L.sz,cntR=0,i,j,k,ans=0;
    ans=L.inv+R.inv;
    for(i=1;i<=40;i++)
    {
        cntL-=L.v[i];
        if(R.v[i]){ans+=cntL*R.v[i];}
        temp.v[i]+=L.v[i]+R.v[i];
    }
    temp.inv=ans;
    return temp;

}
void build(ll node,ll st,ll en)
{
    if(st==en)
    {
        tr[node].v[ar[st]]++;
        tr[node].sz=1;
        return;
    }
    ll mid= (st+en)>>1;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);

    tr[node]=mrg(tr[2*node],tr[2*node+1]);
    return;
}

Node query(ll node, ll st, ll en, ll x, ll y)
{
    if(x<=st && en<=y)
    {
        return tr[node];
    }
    if(y<st || en<x)
    {
        return emp;
    }
    ll mid=(st+en)>>1;

    return mrg(query(2*node,st,mid,x,y),query(2*node+1,mid+1,en,x,y));
}

void update(ll node, ll st,ll en, ll i, ll x)
{
    if(st>i || en<i){return;}
    if(st==en)
    {
        tr[node].v[ar[st]]--;
        ar[st]=x;
        tr[node].v[ar[st]]++;
        tr[node].sz=1;
        return;
    }
    ll mid= (st+en)>>1;
    update(2*node,st,mid,i,x);
    update(2*node+1,mid+1,en,i,x);

    tr[node]=mrg(tr[2*node],tr[2*node+1]);
    return;
}
ll n,m;
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        for(i=1;i<=n;i++){cin>>ar[i];}
        build(1,1,n);
        //for(i=1;i<=2*n;i++){cout<<tr[i].inv<<" . "<<tr[i].sz<<"done,";for(j=1;j<=40;j++){cout<<tr[i].v[j]<<" ";}cout<<endl;}
        while(q--)
        {
            ll x,y,z;
            cin>>z>>x>>y;
            z--;
            if(z)
            {
                update(1,1,n,x,y);
                //for(i=1;i<=2*n;i++){cout<<tr[i].inv<<" . "<<tr[i].sz<<"done, ";for(j=1;j<=40;j++){cout<<tr[i].v[j]<<" ";}cout<<endl;};
            }
            else
            {
                cout<<query(1,1,n,x,y).inv<<endl;
            }
        }
    }
}
//https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/C
//Counting inversion
