#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int ans[30005];

int main()
{
	int i, j, n, m;
	
	while ( cin >> n >> m )
	{
		memset(ans, 0, sizeof(ans));
		
		while ( m -- )
		{
			int v, p;
			
			cin >> v >> p;
			for ( i = n; i >= v; i -- ) ans[i] = max(ans[i], ans[i - v] + v * p );
		}
		
		cout << ans[n] << endl;
	}
	
	return 0;
}
