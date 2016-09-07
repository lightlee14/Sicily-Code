#include <iostream>

using namespace std;

struct node
{
	int val;
	node * left, * right;
};

int node_left[105], node_right[105];

void built(node * n, int * l, int * r)
{
	int i = n->val;
	
	if ( l[i] == -1 ) n->left = NULL;
	else
	{
		n->left = new node;
		n->left->val = l[i];
		built(n->left, l, r);
	}
	
	if ( r[i] == -1 ) n->right = NULL;
	else
	{
		n->right = new node;
		n->right->val = r[i];
		built(n->right, l, r);
	}
}

void mix_order_traversal(node * root)
{
	if ( root == NULL ) return;
	
	if ( root->left != NULL && root->val < root->left->val )
	{
		cout << root->val << ' ';
		mix_order_traversal(root->left);
		mix_order_traversal(root->right);
	}
	else if ( root->right != NULL && root->val < root->right->val )
	{
		mix_order_traversal(root->left);
		cout << root->val << ' ';
		mix_order_traversal(root->right);
	}
	else
	{
		mix_order_traversal(root->left);
		mix_order_traversal(root->right);
		cout << root->val << ' ';
	}
}

void delete_tree(node * n)
{
	if ( n == NULL ) return;
	delete_tree(n->left);
	delete_tree(n->right);
	delete n;
}

int main()
{
	int t;
	node * root = NULL;//注意多次循环的时候结点的删除可能会使程序崩溃 
	
	cin >> t;
	while ( t -- )
	{
		int i, n, m;
		
		cin >> n >> m;
		for ( i = 0; i < n; i ++ ) cin >> node_left[i] >> node_right[i];
		
		root = new node;
		root->val = m;
		built(root, node_left, node_right);
		mix_order_traversal(root);
		
		cout << endl;
		
		delete_tree(root);
	}
	
	return 0;
}
