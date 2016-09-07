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
				sort( s + fir, s + las, comp);//第一个是首指针，第二个是排序的末指针再加一 
				fir = las + 1;//指向下一个字符 
				i ++;
			}
			else i ++;
		}
		
		cout << s << endl;
	}
	
	return 0;
}
