#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int t, n, temp, times;
	
	cin >> t;
	while ( t -- )
	{
		cin >> n;
		
		temp = n;
		times = 0;
		
		//类似于提取数字的处理，加上当前位数的变量times 
		while ( temp )
		{
			if (temp < 10) break;
			
			if ( temp % 10 >= 5) //舍入 
			{
				n += ( 10 - temp % 10) * (int)pow(10,times);
				temp += ( 10 - temp % 10);
			}
			else
			{
				n -= (temp % 10) * (int)pow(10,times);
				temp -= temp % 10;
			}
			temp /= 10;
			times ++;
		}
		
		cout << n << endl;
	}
	
	return 0;
}
