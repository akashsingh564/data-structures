#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100005];
vector <int> p[100005];
vector <int> to_get;
int n,x,q;

int get_com_ans(){
	int prev=0;
	while(1){
		int top=p[to_get[0]].back();
		p[to_get[0]].pop_back();
		for(int i=1;i<q;i++){
			if(p[to_get[i]].back()!=top){  //if top element of any of the path is not same, previous common node is ans
				return prev;
			}
			else
				p[to_get[i]].pop_back();
		}
		prev=top;  //update prev if top nodes of all paths were same as top
	}
}

int path(int u, int v){
	if(u==v){
		//p[v].push_back(u); 
		return 1;
	}
	for(int i=0;i<adj[u].size();i++){
		if(path(adj[u][i],v)==1){
			//p[v].push_back(u);  // uncomment to get path with root in the path
			p[v].push_back(adj[u][i]);
			return 1;
		}
	}
	return 0;
}

int main(){
    cin>>n;
    for(int i=1;i<n;i++){
    	cin>>x;
    	adj[x].push_back(i);
    }
    cin>>q;
    for(int i=0;i<q;i++){
    	cin>>x;
    	to_get.push_back(x);
    	path(0,x);
    	/*for(int i=0;i<p[x].size();i++)  // printing paths to node from root
    		cout<<p[x][i]<<" ";
    	cout<<endl;*/
    }
    cout<<get_com_ans()<<endl;
    return 0;
}
