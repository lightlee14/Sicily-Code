#include <iostream>
#include <cstring>

using namespace std;

struct node
{
	char val;
	node * left;
	node * right;
};

node * build(int n, char * pre, char * in)
{
    //注意strchr返回的是指向那个字符的指针，要减去头指针 
	if ( n <= 0 ) return NULL;
	
	node * ans = new node;
	ans->val = pre[0];
	int order = strchr(in, pre[0]) - in;
	ans->left = build(order, pre + 1, in);
	ans->right = build(n - order - 1, pre + order + 1, in + order + 1);//这里不能用[]，要用指针的加减法 
	
	
	return ans;
}

void BFS(node * root)
{
	if ( root == NULL ) return;
	
	node* q[30];//q是输出序列 
	q[0] = root;
	
	int n = 0, o = 1;//n代表输出节点数，o代表总结点数 
	
	while ( n < o )
	{
		node * temp = q[n];
		n++;
		
		cout << temp->val;
		if ( temp->left != NULL ) q[o++] = temp->left;
		if ( temp->right != NULL ) q[o++] = temp->right;
	}
}

void deleteTree(node * root)
{
	if ( root == NULL ) return;
	if ( root->left != NULL ) deleteTree(root->left);
	if ( root->right != NULL ) deleteTree(root->right);
	delete root;
}

char preorder[30], inorder[30];
 
int main()
{
	int t;
	
	cin >> t;
	while ( t -- )
	{
		cin >> preorder >> inorder;
		int len = strlen(preorder);
		node * root = build(len, preorder, inorder);
		BFS(root);
		cout << endl; 
		deleteTree(root);
	}
	
	return 0;
}
