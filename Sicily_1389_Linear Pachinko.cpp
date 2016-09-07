#include <iostream>
#include <cstring>

using namespace std;

char s[85];

int run_left(char * s,int n)
{
	n --;
	while ( n >= 0 )
	{
		if ( s[n] == '.' ) return 100;
		if ( s[n] == '|' ) return 0;
		if ( s[n] == '\\' ) return 0;
		n --;
	}
	return 100;
}

int run_right(char * s,int n, int len)
{
	n ++;
	while ( n < len )
	{
		if ( s[n] == '.' ) return 100;
		if ( s[n] == '|' ) return 0;
		if ( s[n] == '/' ) return 0;
		n ++;
	}
	return 100;
}

int main()
{
	while ( cin >> s && s[0] != '#' )
	{
		int i, ans = 0, len = strlen(s);
		
		for ( i = 0; i < len; i ++)
		{
			if ( s[i] == '/' ) ans += run_left(s,i);
			if ( s[i] == '\\' ) ans += run_right(s,i,len);
			if ( s[i] == '.' ) ans += 100;
			if ( s[i] == '_' ) ans += 0;
			if ( s[i] == '|' ) ans += run_right(s,i,len) / 2 + run_left(s,i) / 2;
		}
		
		cout << ans / len << endl;
	}
	
	return 0;
}
