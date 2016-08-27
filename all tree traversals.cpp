#include <bits/stdc++.h>
using namespace std;

vector<int> m[100];


typedef struct node{
	int n;
	node* left;
	node* right;
}node;

struct node* insert(int x, struct node* root){
	if(root==NULL){
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->n=x;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
		return root;
	}
	else if(x<root->n)
		root->left=insert(x,root->left);
	else
		root->right=insert(x,root->right);
	return root;
}

void preorder(struct node* root){
	if(root == NULL) return;
	cout<<root->n<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node* root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->n<<" ";
	inorder(root->right);
}

void postorder(struct node* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->n<<" ";
}

void levelorder(struct node* root){  /*****like BFS*****/
	if (root == NULL)  return;
	queue <node*> q;
	q.push(root);
	while(!q.empty()){
		node* current=q.front();
		q.pop();
		if(current!=NULL) cout<<current->n<<" ";
		if(current->left!=NULL) q.push(current->left);
		if(current->right!=NULL) q.push(current->right);
	}
}

void reverselevelorder(struct node* root){
	if (root == NULL)  return;
	queue <node*> q;
	stack <int> s;
	q.push(root);
	while(!q.empty()){
		node* current=q.front();
		q.pop();
		if(current!=NULL) s.push(current->n);
		if(current->left!=NULL) q.push(current->left);
		if(current->right!=NULL) q.push(current->right);
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

void diagonal(struct node* root, int d){
	if(root==NULL) return;
	m[d].push_back(root->n);
	diagonal(root->left,d+1);
	diagonal(root->right,d);
}

void spiral(struct node* root){
	if (root == NULL)  return;
	queue <node*> q1;
	queue <node*> q2;
	q1.push(root);
	while(!q1.empty() || !q2.empty()){
		while(!q1.empty()){
			node* current=q1.front();
			q1.pop();
			if(current!=NULL) cout<<current->n<<" ";
			if(current->right!=NULL) q2.push(current->right);
			if(current->left!=NULL) q2.push(current->left);
		}
		while(!q2.empty()){
			node* current=q2.front();
			q2.pop();
			if(current!=NULL) cout<<current->n<<" ";
			if(current->left!=NULL) q1.push(current->left);
			if(current->right!=NULL) q1.push(current->right);
		}
	}
}

int main(){
	node* root=NULL;
	while(1){
		int x;
		cin>>x;
		if(x==1){
			int n,t;
			cin>>n;
			for(int i=0;i<n;i++){
				cin>>t;
				root=insert(t,root);
			}	
		}
		if(x==2){
			cout<<"preorder"<<endl;
			preorder(root);
			cout<<endl;

			cout<<"inorder"<<endl;
			inorder(root);
			cout<<endl;

			cout<<"postorder"<<endl;
			postorder(root);
			cout<<endl;

			cout<<"level order"<<endl;
			levelorder(root);
			cout<<endl;

			cout<<"reverse level order"<<endl;
			reverselevelorder(root);
			cout<<endl;

			cout<<"diagonal"<<endl;
			diagonal(root,0);
			for(int i=0;i<20;i++){
				for(int j=0;j<m[i].size();j++){
					cout<<m[i][j]<<" ";
				}
				if(m[i].size()!=0)
					cout<<endl;
			}
			cout<<endl;

			cout<<"spiral"<<endl;
			spiral(root);
			cout<<endl;
		}
		if(x==3)
			return 0;
	}
	return 0;
}