#include <iostream>

using namespace std;

int main()
{
	int n, m, i, temp;
	int *hash;
	
	cin >> n >> m;
	hash = new int[m];
	
	for ( i = 0; i < m; i ++ )  hash[i] = -1;
	
	while ( n -- )
	{
		cin >> temp;
		int key = temp % m;
		if ( hash[key]  == -1) hash[key] = temp; //һһ��Ӧ�Ĺ�ϣ�� 
		else
		{
			while ( hash[key] != -1 && key < m ) key ++; //��������͹��� 
			if ( key == m && hash[key] != -1)
			{
				key = 0;
				while ( hash[key] != -1 && key < m ) key ++;
			}
			hash[key] = temp;
		}
	}
	
	for ( i = 0; i < m; i ++ )
	{
		if ( hash[i] != -1) cout << i << '#' << hash[i] << endl;
		else cout << i << '#' << "NULL" << endl;
	}
	
	return 0;
}
