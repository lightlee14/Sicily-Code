#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b)
{
    return a + b < b + a; //b,ba�����Ӧ����bab������bba
}

string s[15];

int main()
{
    int t, n, i;
    
    cin >> t;
    while ( t -- )
    {
        cin >> n;
        
        for ( i = 0; i < n; i ++ ) cin >> s[i];
        sort(s, s + n, comp);
        for ( i = 0; i < n; i ++ ) cout << s[i];
        cout << endl;
    }
    
    return 0;
}
