#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>

using namespace std;

char s[10005];

int main()
{
	int i, j = 0, t;
	
	cin >> t;
	getchar();
	while ( t -- )
	{
		gets(s);
		
		//��mapһһ��Ӧ 
		map<char,char> decode;
		decode.clear();
		char ch[35];
		
		cin >> ch;
		getchar();//�Ѷ���Ļ������յ� 
		for ( i = 0; i < 26; i ++ ) decode[(char)('A' + i)] = ch[i];
		
		j ++;
		cout << j << ' ';
		
		int len = strlen(s);
		for ( i = 0; i < len; i ++ )
		{
			if ( s[i] >= 'A' && s[i] <= 'Z' ) cout << decode[s[i]];
			else cout << s[i];
		}
		
		cout << endl;
	}
	
	return 0;
}
