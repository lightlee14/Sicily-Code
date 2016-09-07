#include <iostream>

using namespace std;

bool path[205][205], city_can_visit[205];

int main()
{
	int n;
	
	while ( cin >> n && n)
	{
		int i, j, m;
		for ( i = 0; i < n; i ++ )
		{
			city_can_visit[i] = false;
			for ( j = 0; j < n; j ++ ) path[i][j] = false;
		}
		
		cin >> m;
		while ( m -- )
		{
			cin >> i >> j;
			path[i][j] = true;
		}
		
		city_can_visit[0] = true;
		for ( i = 0; i < n; i ++)
		for ( j = 0; j < n; j ++) if ( path[i][j]  && ( city_can_visit[i] || city_can_visit[j]) )
		{
			city_can_visit[i] = city_can_visit[j] = true;
		}
		
		if ( city_can_visit[n-1] ) cout << "I can post the letter\n";
		else cout << "I can't post the letter\n";
	}
	
	return 0;
}
