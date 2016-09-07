#include <iostream>
#include <map>

using namespace std;

char ch[105];
string st[105];

int main()
{
	int t;
	
	cin >> t;
	while ( t -- )
	{
		int i, n, t;
		map<char, string> record;
		
		cin >> n;
		for ( i = 0; i < n; i ++)
		{
			cin >> t >> ch[i] >> st[i];
			record[ch[i]] = "Wrong";
		}
		
		for ( i = 0; i < n; i ++) if ( st[i] == "Accept" ) record[ch[i]] = st[i];
		
		map<char, string>::iterator iter;
		
		cout << "Accept: ";
		for ( iter = record.begin(); iter != record.end(); iter ++ ) if ( iter->second == "Accept" ) cout << iter->first;
		cout << endl;
		
		cout << "Wrong: ";
		for ( iter = record.begin(); iter != record.end(); iter ++ ) if ( iter->second == "Wrong" ) cout << iter->first;
		cout << endl << endl;
	}
	
	return 0;
}
