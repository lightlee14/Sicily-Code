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
		
		//��������ȡ���ֵĴ������ϵ�ǰλ���ı���times 
		while ( temp )
		{
			if (temp < 10) break;
			
			if ( temp % 10 >= 5) //���� 
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
