#include <iostream>
#include <iomanip>

using namespace std;

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
int monthl[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};

void chack_data(int & yy, int & mm, int & dd)
{
	bool leap_year = ( yy % 400 == 0 || ( yy % 100 != 0 &&  yy % 4 == 0 ) )? true : false;
	
	if ( leap_year && mm <= 12)
	{
		if ( dd <= monthl[mm] ) return;
		else
		{
			dd -= monthl[mm];
			mm += 1;
			chack_data(yy, mm, dd);
		}
	}
	
	if ( !leap_year && mm <= 12)
	{
		if ( dd <= month[mm] ) return;
		else
		{
			dd -= month[mm];
			mm += 1;
			chack_data(yy, mm, dd);
		}
	}
	
	if ( mm == 13 )
	{
		yy += 1;
		mm = 1;
		chack_data(yy, mm, dd);
	}
}

int main()
{
	int t;
	
	cin >> t;
	while ( t -- )
	{
		int mm, dd, yy;
		
		cin >> mm >> dd >> yy;
		
		int y = yy % 100;
		int c = yy / 100;
		int m;
		if ( mm < 3 )
		{
			int temp = yy - 1;
			y = temp % 100;
			c = temp / 100;
			m = mm + 12;
		}
		else m = mm;
		
		//计算当前星期几，蔡勒公式 
		int week = y + y / 4 + c / 4 - 2 * c + 26 * ( m + 1 ) / 10 + dd - 1;
		while ( week < 0 ) week += 7;
		int day = week % 7;
		dd += 7 - day;
		
		chack_data(yy, mm, dd);
		cout << setw(2) << setfill('0') << mm << ' ' << setw(2) << setfill('0') << dd << ' ' << yy << endl;
	}
	
	return 0;
}
