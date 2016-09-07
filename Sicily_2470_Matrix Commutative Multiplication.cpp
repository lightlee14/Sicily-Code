#include <iostream>
#include <stdio.h>

using namespace std;

int a[1005][1005];

bool is_AB_equal_BA(int n)
{
	int i, j;
	
	for ( i = 0; i < n; i ++)
	for ( j = 0; j < n; j ++)
	{	
		if ( i != j && a[i][j] != 0) return false;
		if ( i == j && a[i][j] != a[0][0]) return false;
	}
	
	return true;
}

int main()
{
	int t, n;
	
	cin >> t;
	while ( t -- )
	{
		//cin >> n;
		scanf("%d",&n);
		
		for ( int i = 0; i < n; i ++)
		for ( int j = 0; j < n; j ++) scanf("%d",&a[i][j]);//cin >> a[i][j];
		
		if ( is_AB_equal_BA(n) ) cout << "YES\n";
		else cout << "NO\n";
	} 
	
	return 0;
}
//不能用cin输入，会超时，但在西西里上判断是WA 
