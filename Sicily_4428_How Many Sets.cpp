#include<iostream>

using namespace std;

int c(int n, int m)
{
	int ans = 1;
	
	for ( int i = 0; i < m; i ++ )
	{
		ans *= n;
		n --;
	}
	
	while ( m > 0 )
	{
		ans /= m;
		m --;
	}
	
	return ans;
}

int main()
{
	int t, m, n;
	
	cin >> t;
	while ( t -- )
	{
		cin >> n >> m;
		cout << c( n + 1 - m , m ) << endl;
	}
	
	return 0;
}
