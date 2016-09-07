#include <iostream>
#include <algorithm>

using namespace std;

bool is_different(int * sin, int ans, int n)
{
	int * copy = new int[n];
	int i, j;
	
	for ( i = 0; i < n; i ++) copy[i] = sin[i] % ans;
	sort(copy, copy + n);//排序之后看看有没有相同数字 
	for ( i = 0; i < n; i ++) if ( copy[i] == copy[i - 1] )
	{
		delete []copy;
		return false;
	}
	
	delete []copy;
	return true;
}

int sin[305]; 

int main()
{
	int n, g, i;
	
	cin >> n;
	while ( n -- )
	{
		cin >> g;
		for ( i = 0; i < g; i ++ ) cin >> sin[i];
		
		int ans = g;
		while ( !is_different(sin, ans, g) ) ans ++;
		cout << ans << endl;
	}
	
	return 0;
} 
