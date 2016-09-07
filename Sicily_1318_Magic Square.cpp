#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int val[20][20];

int main()
{
	int n;
	
	cin >> n;
	while ( cin )
	{
		cout << "n=" << n << ", sum=" << ( n * n / 2 + 1 ) * n << endl;
		
		int i, j, num = 0;
		j = n / 2;
		i = 0;
		memset(val, 0, sizeof(val));
		
		while ( num < n * n )
		{
			num ++;
			
			if ( val[i][j] == 0 ) val[i --][j ++] = num;
			else
			{
				i ++;
				j --;
				
				if ( i == -1 ) i = n - 1;
				if ( i == n ) i = 0;
				if ( j == -1 ) j = n - 1;
				if ( j == n ) j = 0;
				
				while ( val[i][j] != 0 )
				{
					if ( i == n ) i = 0;
					i ++;
				}
				
				val[i --][j ++] = num;
			}
			
			if ( i == -1 ) i = n - 1;
			if ( i == n ) i = 0;
			if ( j == -1 ) j = n - 1;
			if ( j == n ) j = 0;
		}
		
		int length = 1;
		if ( n > 3 ) length = 2;
		if ( n > 9 ) length = 3;
		
		for ( i = 0; i < n; i ++ )
		{
			for ( j = 0; j < n; j ++ )
			cout << ' ' << setw(length) << val[i][j];
			cout << endl;
		}
		
		cin >> n;
		if ( cin ) cout << endl;
	}
	
	return 0;
}
//填完数字往右上角走，假设格子是连起来的，最右上角往右上角走就是左下角，如果被占用了，就退回一步，往下搜索空格填数字 
