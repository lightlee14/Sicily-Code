#include <iostream>

using namespace std;

int ans[25];

int main()
{
	int t, n = 0;
	
	cin >> t;
	while ( t -- )
	{
		int h, m, s;
		char ch;
		
		cin >> h >> ch >> m >> ch >> s;
		n ++;
		
		int i, j = 0;
		for ( i = 0 ; i < 6; i ++)
		{
			ans[j ++] = s & 1;
			s >>= 1;
			
			ans[j ++] = m & 1;
			m >>= 1;
			
			ans[j ++] = h & 1;
			h >>= 1;
		}
		ans[j] = '\0';
		
		cout << n << ' ';
		for ( i = 17; i >= 0; i -- ) cout << ans[i];
		cout << ' ';
		
		for ( i = 0; i < 3; i ++)
		for ( j = 17 - i; j >= 0; j -= 3 ) cout << ans[j];
		cout << endl; 
	}
	
	return 0;
}
//用位运算取二进制，注意保存在数组中的顺序和输出顺序之间的关系 
