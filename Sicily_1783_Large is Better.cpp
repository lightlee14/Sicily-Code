#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char s[105];

bool comp(char a, char b) { return a > b; }

int main()
{
	int t;
	
	cin >> t;
	while ( t -- )
	{
		cin >> s;
		
		int i = 0,fir = 0, las = 0;
		int len = strlen(s);
		
		while ( i <= len )
		{
			if ( s[i] == '0' || s[i] == '\0' )
			{
				las = i;
				sort( s + fir, s + las, comp);//��һ������ָ�룬�ڶ����������ĩָ���ټ�һ 
				fir = las + 1;//ָ����һ���ַ� 
				i ++;
			}
			else i ++;
		}
		
		cout << s << endl;
	}
	
	return 0;
}
