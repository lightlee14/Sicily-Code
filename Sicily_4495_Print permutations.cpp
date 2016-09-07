#include <iostream>
#include <cstring>

using namespace std;

char sources[50], creates[50];
int len;

void print_permutations(char * create, char * source, int len_c)
{
	int i;
	
	if ( len_c == len )
	{
		for ( i = 0; i < len_c; i ++ ) cout << create[i];
		cout << endl;
		return;
	}
	
	bool * has_used = new bool [30];
	for ( i = 0; i < 30; i ++ ) has_used[i] = false;
	
	//���ù����ַ���� 
	for ( i = 0; i < len_c; i ++ ) has_used[create[i] - 'A'] = true;
	
	//���ֵ�������δ������ַ� 
	for ( i = 0; i < len; i ++ ) if ( !has_used[source[i] - 'A'] )
	{
		create[len_c] = source[i];
		print_permutations(create, source, len_c + 1);//ע�ⲻҪ�޸�len_c��ֵ 
	}
	
	delete []has_used;
}

int main()
{
	cin >> sources;
	len = strlen(sources);
	//���Զ�ԭ�������򣬾Ϳ��԰����ֵ������ţ���Ȼ�ǰ��ַ���˳���ŵ� 
	creates[0] = '\0';
	print_permutations(creates, sources, 0);
	
	return 0;
}
