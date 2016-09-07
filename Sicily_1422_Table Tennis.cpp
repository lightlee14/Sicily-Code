#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if ( b == 0 ) return a;
	return gcd ( b, a % b );
}

int main()
{
	int m, n;
	while ( cin >> m >> n )
	{
		int ans, temp = gcd(m, n);
		m /= temp;
		n /= temp;
		ans = m + n - 2;
		if ( m % 2 == 0 && n % 2 == 0) cout << "A ";
		if ( m % 2 == 1 && n % 2 == 0) cout << "D ";
		if ( m % 2 == 0 && n % 2 == 1) cout << "B ";
		if ( m % 2 == 1 && n % 2 == 1) cout << "C "; 
		cout << ans << endl;
	}
	
	return 0;
}
//将小球轨迹展开分析即可 
