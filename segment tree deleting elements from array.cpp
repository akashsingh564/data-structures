#include <bits/stdc++.h>
using namespace std;
#define maxn 500005
#define ll long long

ll tree[4*maxn];
vector <string> rname(maxn);
vector <ll> rtime(maxn);
vector <ll> rorder(maxn-1);
ll t,n,x;
string rn;

void build(ll node, ll start, ll end){
	if(start==end)
		tree[node]=1;
	else{
		ll mid=(start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}

ll query(ll node, ll start, ll end, ll pos){
	if(start==end){
		tree[node]=0;
		return start;
	}
	tree[node]=tree[node]-1;
	ll idx=2*node;
	ll mid=(start+end)/2;
	if(pos<=tree[idx])
		return query(2*node, start, mid, pos);
	else
		return query(2*node+1, mid+1, end, pos-tree[idx]);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	    cin>>n;
	    for(ll i=0;i<n;i++)
	    	cin>>rname[i];
	    for(ll i=0;i<n;i++)
	    	cin>>rtime[i];
	    for(ll i=0;i<n-1;i++)
	    	cin>>rorder[i];
	    
	    rorder[n-1]=1;
	    build(1,1,n);
	    
	    ll ans=0;
	    for(ll i=0;i<n;i++){
	    	ll val=query(1,1,n,rorder[i]);
	    	ans=max(ans,rtime[val-1]);
	    	cout<<rname[val-1]<<" "<<ans<<endl;
	    }
	}
    return 0;
}