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
    //ע��strchr���ص���ָ���Ǹ��ַ���ָ�룬Ҫ��ȥͷָ�� 
	if ( n <= 0 ) return NULL;
	
	node * ans = new node;
	ans->val = pre[0];
	int order = strchr(in, pre[0]) - in;
	ans->left = build(order, pre + 1, in);
	ans->right = build(n - order - 1, pre + order + 1, in + order + 1);//���ﲻ����[]��Ҫ��ָ��ļӼ��� 
	
	
	return ans;
}

void BFS(node * root)
{
	if ( root == NULL ) return;
	
	node* q[30];//q��������� 
	q[0] = root;
	
	int n = 0, o = 1;//n��������ڵ�����o�����ܽ���� 
	
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
