#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

int diameter(Node *root, int &res){
	if(!root) return 0;
	
	int lh = diameter(root->left, res);
	int rh = diameter(root->right, res);
	
	int temp = 1 + max(lh, rh);
	res = max(res, 1 + lh + rh);
	
	return temp;
}

int main(){
	int res = INT_MIN;
	
	struct Node *root = new Node(1);
	root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
	
	int x = diameter(root, res);

	cout<<res;
	
	return 0;
}
