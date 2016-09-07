#include <iostream>
#include <cstring>

using namespace std;

bool palindrome(char * s)
{
	int i, j, len = strlen(s);
	
	i = 0;
	j = len - 1;
	while ( i < len && j >= 0 )
	{
		if ( s[i] != s[j] ) return false;
		i++;
		j--; 
	}
	
	return true;
}

char input[25], number[25];

int main()
{
	int t, i;
	
	cin >> t;
	while ( t -- )
	{
		cin >> input;
		
		int len = strlen(input);
		for ( i = 0; i < len; i ++ )
		{
			switch ( input[i] )
			{
				case 'A' : case 'B' : case 'C' : case 'a' : case 'b' : case 'c' : number[i] = '2'; break;
				case 'D' : case 'E' : case 'F' : case 'd' : case 'e' : case 'f' : number[i] = '3'; break;
				case 'G' : case 'H' : case 'I' : case 'g' : case 'h' : case 'i' : number[i] = '4'; break;
				case 'J' : case 'K' : case 'L' : case 'j' : case 'k' : case 'l' : number[i] = '5'; break;
				case 'M' : case 'N' : case 'O' : case 'm' : case 'n' : case 'o' : number[i] = '6'; break;
				case 'P' : case 'Q' : case 'R' : case 'S' : case 'p' : case 'q' : case 'r' : case 's' : number[i] = '7'; break;
				case 'T' : case 'U' : case 'V' : case 't' : case 'u' : case 'v' : number[i] = '8'; break;
				case 'W' : case 'X' : case 'Y' : case 'Z' : case 'w' : case 'x' : case 'y' : case 'z' : number[i] = '9'; break;
			}
		}
		number[i] = '\0';
		
		if ( palindrome(number) ) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
