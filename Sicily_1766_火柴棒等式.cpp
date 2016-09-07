#include <iostream>

using namespace std;

int match[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
	int n;
	
	while ( cin >> n )
	{
		int i, j, ans = 0;
		int need_match = 0;
		
		for ( i = 0; i < 1111; i ++ )
		for ( j = 0; j < 1111; j ++ )
		{
			int tempi = i;
			int tempj = j;
			int tempans = i + j;
			
			//注意提取数字的时候，0要注意 
			if ( tempi == 0 ) need_match += 6;
			while ( tempi )
			{
				need_match += match[tempi % 10];
				tempi /= 10;
			}
			
			if ( tempj == 0 ) need_match += 6;
			while ( tempj )
			{
				need_match += match[tempj % 10];
				tempj /= 10;
			}
			
			if ( tempans == 0 ) need_match += 6;
			while ( tempans )
			{
				need_match += match[tempans % 10];
				tempans /= 10;
			}
			
			if ( need_match == n - 4 ) ans ++;
			need_match = 0;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
