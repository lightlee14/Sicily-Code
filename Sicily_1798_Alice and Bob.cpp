#include <iostream>

using namespace std;

int main()
{
    int n;
    
    while ( cin >> n && n != 0)
    {
        if ( n % 2 ) cout << "Bob\n";
        else cout << "Alice\n";
    }
}
