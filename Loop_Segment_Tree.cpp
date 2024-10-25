#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//uniform_int_distribution<int> dist(1, 1000000);
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl<<flush;
#define endl '\n'
#define INF 1e16
const ll M=1e9+7;
const ll N=2e5+1;
const ll LOG=18;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
ll arr[N], st[2*N];
void build()
{
    for(int i=1;i<=n;i++){st[i+n]=arr[i];}
    for(int i=n;i>=1;i--)
    {
        st[i]=st[(i<<1)]+st[(i<<1)|1];
        //st[i] = st[2*i]+st[2*i+1];      Use bitmanipulation for faster result
    }
}
void update(ll idx, ll val)
{
    idx+=n;
    st[idx]=val;
    for(int i=idx/2;i>0;i/=2)
    {
        st[i]=st[(i<<1)]+st[(i<<1)|1];
    }
}
ll query(ll l, ll r)
{
    ll sum=0;
    l+=n;
    r+=n;
    while(l<=r)
    {
        if(!(r&1)){sum+=st[r--];}
        if(l&1){sum+=st[l++];}
        r>>=1;
        l>>=1;
    }return sum;
}
int32_t main()
{
    fast
    ll i,j,k,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        for(i=1;i<=n;i++){cin>>arr[i];}
        build();
        while(q--)
        {
            ll type;
            cin>>type;
            if(type==1)
            {
                //Update
                ll idx,val;
                cin>>idx>>val;
                idx++;
                update(idx,val);
            }
            else
            {
                //query
                ll l, r;
                cin>>l>>r;
                l++;
                cout<<query(l,r)<<endl;
            }
        }
    }
}
//The difference between previous submission is bit_ops
//Segment tree edu. Step 1 A.
