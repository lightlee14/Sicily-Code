#include <iostream>
#include <cstring>

using namespace std;

char s1[1000005], s2[1000005];

void showans(int n)
{
	if ( n == 0 )
	{
		cout << "{}";
		return;
	}
	
	cout << '{';
	for (int i = 0; i < n - 1; i ++)
	{
		showans(i);
		cout<<',';
	}
	showans(n - 1);
	cout << '}';
}

int main()
{
	int t;
	
	cin >> t;
	while ( t --)
	{
		int a, b;
		
		cin >> s1 >> s2;
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		
		//ת��������ֻҪ������ж��ٸ�}�ͺ��ˣ�����Ҫ��1 
		a = len1 - 1;
		while ( s1[a --] == '}' );
		a = len1 - 3 - a;//ע�⴦�� 
		
		b = len2 - 1;
		while ( s2[b --] == '}' );
		b = len2 - 3 - b;
		
		showans(a + b);
		cout << endl;
	}
	
	return 0;
}
