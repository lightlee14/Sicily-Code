#include <iostream>
#include <cmath>
#include <iomanip>

#define pi acos(-1)

using namespace std;

int main()
{
	double a, b, k1, c, d, k2;
	int n;
	
	cin >> n;
	while ( n -- )
	{
		cin >> a >> b >> k1;
		cin >> c >> d >> k2;
		k1 = tan( (270 - k1) * pi / 180);
		k2 = tan( (270 - k2) * pi / 180);
		
		double ansx, ansy;
		ansx = ( c * k2 - a * k1 + b - d ) / ( k2 - k1 );
		ansy = ( k1 * ( k2 * c - d ) + k2 * ( b - k1 * a ) ) / ( k2 - k1 );
		//���д�� ansy=(ansx-a)*k1+b �ǻ�WA,��������Ϊx��������� 
		
		cout << fixed << setprecision(4) << ansx << ' ' << ansy << endl;
	}
	
	return 0;
}
