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
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
const ll M =1e9+7;
const ll N =3e5+1;
struct BIT
{
    ll n;
    vector<ll>bit;
    BIT(ll n)
    {
        this->n=n+1;
        bit.assign(n+1,0);
    }

    BIT(vector<ll>a):BIT(a.size())
    {
        for(size_t i=0;i<a.size();i++)
        {
            add(i,a[i]);
        }
    }

    ll sum(ll idx)
    {
        ll ans=0;
        for(++idx;idx>0;idx-=(idx&-idx))
        {
            ans+=bit[idx];
        }
        return ans;
    }

    ll sum(ll l, ll r){return sum(r)-sum(l-1);}

    void add(ll idx , ll delta)
    {
        for(++idx;idx<n;idx+= (idx&-idx))
        {
            bit[idx]+=delta;
        }
    }
};
ll n,m;
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        vector<ll>v(n);
        for(i=0;i<n;i++){cin>>v[i];}
        BIT bit(v);
        cout<<"Case "<<++cs<<": "<<endl;
        while(q--)
        {
            ll x,y,z;
            cin>>z;z--;
            if(z)
            {
                cin>>x>>y;
                z--;
                if(z)
                {
                    cout<<bit.sum(x,y)<<endl;
                }
                else
                {
                    bit.add(x,y);
                    v[x]+=y;
                }
            }
            else
            {
                cin>>x;
                cout<<v[x]<<endl;
                bit.add(x,-v[x]);
                v[x]=0;
            }
        }
    }
}
/***
Most basic BIT/Fenwick Tree problem.
LOJ-1112, Curious Robin Hood
https://lightoj.com/problem/curious-robin-hood
***/
