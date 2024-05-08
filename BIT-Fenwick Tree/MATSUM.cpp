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
const ll N =3e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
struct Two_D_BIT
{
    vector<vector<ll>>v;
    ll n,m;
    Two_D_BIT(ll n,ll m)
    {
        this->n=n;
        this->m=m;
        v.resize(n,vector<ll>(m));
    }

    Two_D_BIT(vector<vector<ll>>&a):Two_D_BIT(a.size(),a[0].size())
    {
        for(size_t i=0;i<a.size();i++)
        {
            for(size_t j=0;j<a[0].size();j++)
            {
                add(i,j,a[i][j]);
            }
        }
    }

    ll sum(ll x,ll y)
    {
        ll ans=0;
        for(int i=x;i>=0;i=(i&(i+1))-1)
        {
            for(int j=y;j>=0;j=(j&(j+1))-1)
            {
                ans+=v[i][j];
            }
        }
        return ans;
    }

    void add(ll x, ll y,ll delta)
    {
        for(int i=x;i<n;i=i|(i+1))
        {
            for(int j=y;j<m;j=j|(j+1))
            {
                v[i][j]+=delta;
            }
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
        cin>>n;
        vector<vector<ll>>v(n+1,vector<ll>(n+1,0));
        Two_D_BIT bit(n+1,n+1);
        while(k)
        {
            string s;cin>>s;
            if(s[2]=='M')
            {
                ll a,b,c,d;
                cin>>a>>b>>c>>d;
                a++;b++;c++;d++;
                cout<<endl<<bit.sum(c,d)-bit.sum(c,b-1)-bit.sum(a-1,d)+bit.sum(a-1,b-1);
            }
            else if(s[2]=='T')
            {
                ll a,b,c;
                cin>>a>>b>>c;
                a++;b++;
                bit.add(a,b,c-v[a][b]);
                v[a][b]=c;
            }
            else{break;}
        }
    }
}
/***
MATSUM-Matrix Summation(SPOJ)

Description:
This problem takes a lot of optimization. It's must to use fast io. 
The intended solution is BIT and there are no approach other than BIT
1)ios_base::sync_with_stdio();cin.tie();cout.tie();
2)\n instead of endl;
3)Fenwick tree instead of 2D segment tree.
***/
