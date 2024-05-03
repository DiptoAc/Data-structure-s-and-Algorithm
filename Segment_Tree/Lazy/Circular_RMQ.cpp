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

ll n,m;
vector<ll>v(N,0),lazy(4*N,0),tr(4*N,0);

void build(ll node, ll low, ll high)
{
    if(low==high)
    {
        tr[node]=v[low];
        return;
    }

    ll mid= (low+high)/2;

    build(2*node, low, mid);
    build(2*node+1, mid+1,high);

    tr[node]= min(tr[2*node],tr[2*node+1]);
    return;
}

void rangeUpdate(ll node,ll low, ll high, ll a, ll b, ll val)
{
    if(lazy[node])
    {
        tr[node]+=lazy[node];
        if(low!=high)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(b<low || high<a){return;}

    if(a<=low && high <=b)
    {
        tr[node]+=val;
        if(low!=high)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    
    ll mid=(low+high)/2;
    rangeUpdate(2*node,low,mid,a,b,val);
    rangeUpdate(2*node+1,mid+1,high,a,b,val);
    
    tr[node]=min(tr[2*node],tr[2*node+1]);

}

ll minQuery(ll node, ll low,ll high, ll a, ll b)
{
    if(lazy[node])
    {
        tr[node]+=lazy[node];
        if(low!=high)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(high<a || b<low){return LLONG_MAX;}

    if(a<=low && high<=b){return tr[node];}

    ll mid=(low+high)/2;
    return min(minQuery(2*node, low,mid, a,b),minQuery(2*node+1,mid+1,high,a,b));
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(i=1; i<=n; i++){cin>>v[i];}
        build(1,1,n);
        //cout<<"node ";for(i=1;i<=7;i++){cout<<tr[i]<<" ";}cout<<endl;

        cin>>q;
        while(q--)
        {
            string s;
            getline(cin, s);
            istringstream ss(s);
            vector <ll> temp;
            ll tmp;
            while(ss >> tmp){temp.push_back(tmp);}
            if(temp.size() == 0)
            {
                q ++;
                continue;
            }
            //cout<<"temp ";for(auto &it:temp){cout<<it<<" ";}cout<<endl;
            if(temp.size()==3)
            {
                if(temp[0]>temp[1])
                {
                    rangeUpdate(1,1,n,temp[0]+1,n,temp[2]);
                    rangeUpdate(1,1,n,1,temp[1]+1,temp[2]);
                }
                else
                {
                    rangeUpdate(1,1,n,temp[0]+1,temp[1]+1,temp[2]);
                }
                //cout<<"node ";for(i=1;i<=7;i++){cout<<tr[i]<<" ";}cout<<endl;
            }
            else
            {
                if(temp[0]>temp[1])
                {
                    cout<<min(minQuery(1,1,n,temp[0]+1,n),minQuery(1,1,n,1,temp[1]+1))<<endl;
                }
                else
                {
                    cout<<minQuery(1,1,n,temp[0]+1,temp[1]+1)<<endl;
                }
            }
        }
    }

}
/***
https://codeforces.com/contest/52/problem/C
Circular RMQ

Input:
4
1 2 3 4
4
3 0
3 0 -1
0 1
2 1

Expected Output:
1
0
0
***/
