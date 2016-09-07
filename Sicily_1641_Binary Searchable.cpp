#include <iostream>

using namespace std;

bool is_max(int * arr, int n, int fir, int las)
{
	int i;
	
	for ( i = fir; i < las; i ++ ) if ( arr[i] > n ) return false;
	return true;
}

bool is_min(int * arr, int n, int fir, int las)
{
	int i;
	
	for ( i = fir; i < las; i ++ ) if ( arr[i] < n ) return false;
	return true;
}

int a[1005];

int main()
{
	int n;
	
	while ( cin >> n )
	{
		int i, count = 0;
		
		for ( i = 0; i < n; i ++ ) cin >> a[i];
		//看看有几个数是比后面的数都小，比前面的数都大 
		for ( i = 0; i < n; i ++ ) if ( is_min(a, a[i], i + 1, n) && is_max(a, a[i], 0, i) ) count ++;
		
		cout << count << endl;
	}
	
	return 0;
}
