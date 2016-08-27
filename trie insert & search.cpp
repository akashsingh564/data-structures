#include <bits/stdc++.h>
using namespace std;

struct trie{
	trie* next[26];
	int weight;
	trie(){
		for(int i=0;i<26;i++)
			next[i]=NULL;
		weight=0;
	}
};

void insert(string &s,int w, trie* root){
	int l=s.size();
	for(int i=0;i<l;i++){
		int index=s[i]-'a';
		if(root->next[index]==NULL)
			root->next[index]=new trie();
		root->next[index]->weight=max(root->next[index]->weight,w);
		root=root->next[index];
	}
}

/*void insert(string &s,int w, trie* root){
	for(auto c:s){
		if(root->next[c-'a']==NULL)
			root->next[c-'a']=new trie();
		root->next[c-'a']->weight=max(root->next[c-'a']->weight,w);
		root=root->next[c-'a'];
	}
}*/

trie* insert(string &s, int w, int i, trie* root){
	int cur=s[i]-'a';
	if(root->next[cur]==NULL)
		root->next[cur]=new trie();
	root->next[cur]->weight=max(root->next[cur]->weight,w);
	if(i+1<s.size())
		root->next[cur]=insert(s,w,i+1,root->next[cur]);
	return root;
}

/*int search(string &s, trie* root){
	int ans=-1;
	for(auto c:s){
		if(root->next[c-'a']==NULL)
			return -1;
		ans=root->next[c-'a']->weight;
		root=root->next[c-'a'];
	}
	return ans;
}*/

int search(string &s, trie* root){
	int l=s.size();
	int ans=-1;
	for(int i=0;i<l;i++){
		int index=s[i]-'a';
		if(root->next[index]==NULL)
			return -1;
		ans=root->next[index]->weight;
		root=root->next[index];
	}
	return ans;
}

int main(){
    int n,q,w;
    string s;
    trie* root=new trie();
    cin>>n>>q;
    while(n--){
    	cin>>s>>w;
    	//insert(s,w,root);
    	root=insert(s,w,0,root);
    }
    while(q--){
    	cin>>s;
    	cout<<search(s,root)<<endl;
    }
    return 0;
}
