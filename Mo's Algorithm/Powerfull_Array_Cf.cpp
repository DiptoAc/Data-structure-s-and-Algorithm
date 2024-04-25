//Mo's algorithm. Codeforces Powerful array.
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
ll ans=0,block_size;
struct Queries
{
    ll l,r,idx;
    Queries(ll a,ll b, ll c)
    {
        l=a;
        r=b;
        idx=c;
    }
//You can provide a comparator function for sorting in you structure.
    bool operator<(Queries other) const
    {
        if(l/block_size != other.l/block_size){return l<other.l;}
        return (l/ block_size & 1) ? (r < other.r) : (r > other.r);//when odd cur_r will go upwards otherwise downwards
    }
    //The comparator function was taken form Mehedi_34's code.
};
ll n,m;
vector<ll>v(N),mp(1000001),print(N);
vector<Queries>qry;
//inline Keyword take's the function into the code. It reduces the overhead for calling and function and returning the calculated value.
inline void add(ll ind)
{
    ll num=v[ind];
    ans+=num*(2*mp[num]+1);
    mp[num]++;
}
inline void sub(ll ind)
{
    ll num=v[ind];
    ans+=num*(-2*mp[num]+1);
    mp[num]--;
}
int32_t main()
{
    fast
    ll i,j,k,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        for(i=1;i<=n;i++){cin>>v[i];}
        for(i=1;i<=q;i++)
        {
            ll x,y;
            cin>>x>>y;
            qry.pb(Queries(x,y,i));
        }
        block_size=sqrt(n);
        sort(qry.begin(),qry.end());
        ll cur_l=1,cur_r=0;
        for(auto [l,r,idx]:qry)
        {
            while(cur_l>l){add(--cur_l);}    //When expanding, we move to the index first then add the element of that index
            while(cur_l<l){sub(cur_l++);}    //When compressing, we delete the element of current index, then move the index
            while(cur_r>r){sub(cur_r--);}
            while(cur_r<r){add(++cur_r);}
            print[idx]=ans;
        }
        for(i=1;i<=q;i++){cout<<print[i]<<endl;}
    }
}
/*
You don't have to divide the array into sqrt(n) part in Mo's algorithm. 
You just have to sort the query based on the first index and if first index lies on the same block, then rearrange them in a staircase manner.
*/
