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

int maxPathSum(Node *root, int &res){
	if(!root) return 0;
	
	int lh = maxPathSum(root->left, res);
	int rh = maxPathSum(root->right, res);
	
	int temp = max(max(lh, rh) + root->data, root->data);
	int tempAns = max(temp, lh + rh + root->data);
	res = max(res, tempAns);
	
	return temp;
}

int main(){
	int res = INT_MIN;
	
	struct Node *root = new Node(10);
    root->left        = new Node(2);
    root->right       = new Node(10);
    root->left->left  = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left   = new Node(3);
    root->right->right->right  = new Node(4);
	
	int x = maxPathSum(root, res);

	cout<<res;
	
	return 0;
}
