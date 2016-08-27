#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node 
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* insert(struct node* root,int x)
{
	if(root == NULL)
	{
		struct node* temp = (node*)malloc(sizeof(struct node));
		temp->data = x;
		temp->left = NULL;
		temp->right  = NULL;
		root = temp;
		return root;
	}
	else if(x <= root->data)
		root->left = insert(root->left,x);
	else
		root->right = insert(root->right,x);
	return root; 
}
void inorder(struct node* root)
{
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
struct node* search(struct node* root,int x)
{
	if(root == NULL)
		return NULL;
	if(root->data == x)
		return root;
	else if(x < root->data)
		return search(root->left,x);
	else if(x > root->data)
		return search(root->right,x); 
}
struct node* min(struct node* root)
{
	if(root == NULL)
		return root;
	if(root->left == NULL)
		return root;
	return min(root->left);
}
struct node* max(struct node* root)
{
	if(root == NULL)
		return root;
	if(root->right == NULL)
		return root;
	while(root->right != NULL)
		root = root->right;
	return root;
}
struct node* successor(struct node* root,int x)
{
	struct node* curr = search(root,x);
	if(curr == NULL)
		return NULL;
	if(curr->right != NULL)
		return min(curr->right);  //return minimum of right sub tree;
	else
	{
		struct node* success = NULL;
		while(root != curr)
		{
			if(curr->data <= root->data)
			{
				if(curr->data < root->data		)
					success = root;
				root = root->left;
			}
			else
				root = root->right;
		}
		return success;
	}
}
struct node* predecessor(struct node* root,int x)
{
	struct node* curr = search(root,x);
	if(curr == NULL)
		return NULL;
	if(curr->left != NULL)
		return max(curr->left);
	else
	{
		//cout<<"fofo";
		struct node* pred = NULL;
		while(root != curr)
		{
			if(curr->data > root->data)
			{
				pred = root;
				root = root->right;
			}
			else
				root = root->left;
		}
		return pred;
	}
}
struct node* del(struct node* root,int x)
{
	if(root == NULL) return root;
	else if(x < root->data) root->left = del(root->left,x);
	else if(x > root->data) root->right = del(root->right,x);
	else
	{
		//case 1
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		//case 2
		else if(root->left == NULL)
		{
			struct node* temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL)
		{
			struct node* temp = root;
			root = root->left;
			free(temp);
		}
		//case 3
		else
		{
			struct node* temp = min(root->right);
			root->data = temp->data;
			root->right = del(root->right,temp->data);
		}
	}
	return root;

}int main()
{
	int n=0,i=0,x=0;
	struct node* root = NULL;
	struct node* temp = NULL;
	while(1)
	{
		cin>>n;
		if(n == 1)
		{
			cin>>x;
			root = insert(root,x);
		}
		if(n == 2)
		{
			temp = min(root);
			cout<<temp->data<<endl;
		}
		if(n == 3)
		{
			temp = max(root);
			if(temp == NULL)
				cout<<"NULL";
			else
				cout<<temp->data<<endl;
		}
		if(n == 4)
		{
			cin>>x;
			temp = search(root,x);
			if(temp == NULL)
				cout<<"NULL";
			else
				cout<<temp->data<<endl;
		}
		if(n == 5)//traversal
			inorder(root);
		if(n == 6)//successor
		{
			cin>>x;
			temp = successor(root,x);
			if(temp == NULL)
				cout<<"NULL"<<endl;
			else
				cout<<temp->data<<endl;
		}	
		if(n == 7)//predecessor
		{
			cin>>x;
			temp = predecessor(root,x);
			if(temp == NULL)
				cout<<"NULL"<<endl;
			else
				cout<<temp->data<<endl;
		}	
		if(n == 8)
		{
			cin>>x;
			root = del(root,x);
		}
		if(n == 9)
			return 0;
	}
	return 0;
}