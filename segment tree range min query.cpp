#include <bits/stdc++.h>
using namespace std;

int n,q,x,y;
char c;
int a[100005];
int tree[200010];

void build(int node, int start, int end){
	if(start==end)
		tree[node]=a[start];
	else{
		int mid=(start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node]=min(tree[2*node], tree[2*node+1]);
	}
}

int query(int node, int start, int end, int l, int r){
	if(start>end || start>r || l>end)
		return INT_MAX;
	if(l<=start && r>=end)
		return tree[node];
	else{
		int mid=(start+end)/2;
		int p1=query(2*node, start, mid, l, r);
		int p2=query(2*node+1, mid+1, end, l ,r);
		return min(p1,p2);
	}
}

void update(int node, int start, int end, int idx, int val){
	if(start==end){
		a[idx]=val;
		tree[node]=val;
	}
	else{
		int mid=(start+end)/2;
		if(start<=idx && idx<=mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
		tree[node]=min(tree[2*node], tree[2*node+1]);
	}
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    build(1,1,n);
    while(q--){
    	cin>>c>>x>>y;
    	if(c=='q'){
    		cout<<query(1,1,n,x,y)<<endl;
    	}
    	if(c=='u'){
    		update(1,1,n,x,y);
    	}
    }
    return 0;
}
